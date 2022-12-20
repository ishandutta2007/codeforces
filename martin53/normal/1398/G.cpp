#include<bits/stdc++.h>
using namespace std;

pair<double,double> add(pair<double,double> a,pair<double,double> b)
{
    return {a.first+b.first,a.second+b.second};
}

pair<double,double> mult(pair<double,double> a,pair<double,double> b)
{
    return {a.first*b.first-a.second*b.second,a.second*b.first+a.first*b.second};
}


const int nmax=2e5+42,MX=1<<20;
const double pi=acos(-1);

int n,x,y;

int inp[nmax];

vector<int> a,b;

int seen[MX];



void fft(vector< pair<double,double> > &cur,int type)
{
    //for(auto w:cur)cout<<w<<" ";cout<<endl;

    int n=cur.size();

    if(n==1)return;

    vector< pair<double,double> > even={},odd={};

    double base=2*pi/n;

    for(int i=0;i<n;i++)
    {
        if(i%2==0)even.push_back(cur[i]);
        else odd.push_back(cur[i]);
    }

    fft(even,type);
    fft(odd,type);

    //cout<<"was: ";for(auto w:cur)cout<<w<<" ";cout<<endl;

    pair<double,double> step={cos(type*base),sin(type*base)};
    pair<double,double> now={1,0};

    for(int i=0;i<n;i++)
    {
        int where=i%(n/2);

        cur[i]=add(even[where],mult(odd[where],now));

        now=mult(now,step);
    }

    /*
    cout<<"is: ";for(auto w:cur)cout<<w<<" ";cout<<endl;
    cout<<"---"<<endl;
    */
    if(type==-1)
    {
        for(auto &w:cur)
        {
            w.first=w.first/2;
            w.second=w.second/2;
        }
    }

}

vector<int> mult()
{
    int w=a.size()+b.size();

    while((w&(w-1)))w++;

    while(a.size()<w)a.push_back(0);
    while(b.size()<w)b.push_back(0);

    vector< pair<double,double> > a_={},b_={};

    for(int i=0;i<w;i++)
    {
        pair<double,double> cur;
        cur={a[i],0.0};

        a_.push_back(cur);

        cur={b[i],0.0};

        b_.push_back(cur);
    }

    fft(a_,1);

    fft(b_,1);

    /*
    for(auto w:a_)cout<<w<<" ";cout<<endl;
    for(auto w:b_)cout<<w<<" ";cout<<endl;
    */

    for(int i=0;i<w;i++)
        a_[i]=mult(a_[i],b_[i]);

    //cout<<"a_ ";for(auto w:a_)cout<<w<<" ";cout<<endl;

    fft(a_,-1);

    vector<int> ret={};
    for(int i=0;i<w;i++)
        ret.push_back(a_[i].first+0.5);

    //for(auto w:ret)cout<<w<<" ";cout<<endl;

    return ret;
}

int solved[MX];

void prec()
{
    for(int i=0;i<=x;i++)
    {
        a.push_back(0);
        b.push_back(0);
    }

    for(int i=0;i<=n;i++)
    {
        a[inp[i]]++;
        b[x-inp[i]]++;
    }

    vector<int> ret=mult();

    for(int i=x+1;i<=x+x;i++)
        if(ret[i])
        {
            seen[2*(i-x+y)]=1;
            //cout<<"seen "<<2*(i-x+y)<<endl;
        }

    memset(solved,-1,sizeof(solved));

    for(int i=1;i<MX;i++)
        if(seen[i])
            for(int j=i;j<MX;j+=i)
                solved[j]=max(solved[j],i);
}

int main()
{
    scanf("%i%i%i",&n,&x,&y);

    for(int i=0;i<=n;i++)scanf("%i",&inp[i]);

    /*
    n=2e5;
    x=n;
    y=n;
    for(int i=0;i<=n;i++)inp[i]=i;
    */
    prec();

    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        int cur;
        scanf("%i",&cur);

        printf("%i\n",solved[cur]);
    }
    return 0;
}