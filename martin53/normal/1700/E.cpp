#include<bits/stdc++.h>
using namespace std;

int n,m;

vector< vector<int> > inp;

int x_[5]={-1,1,0,0,0};
int y_[5]={0,0,-1,1,0};

bool in(int i,int j)
{
    return 0<=i&&i<n&&0<=j&&j<m;
}

bool test(int i,int j)
{
    if(in(i,j)==0)return 0;

    for(int t=0;t<4;t++)
        if(in(i+x_[t],j+y_[t])&&inp[i+x_[t]][j+y_[t]]<inp[i][j])
            return 0;

    return 1;
}

set< pair< pair<int,int>, pair<int,int> > > seen;

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=0;i<n;i++)
    {
        inp.push_back({});

        for(int j=0;j<m;j++)
        {
            int cur;
            scanf("%i",&cur);

            inp[i].push_back(cur);
        }
    }

    int local=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            local+=test(i,j);

    if(local==1)
    {
        printf("0\n");
        return 0;
    }

    if(local>=12)
    {
        printf("2\n");
        return 0;
    }

    int cnt=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int cur=local;

            for(int t=0;t<5;t++)
                cur=cur-test(i+x_[t],j+y_[t]);

            if(cur<=6&&cur!=local)
            {
                for(int p=0;p<n;p++)
                    for(int q=0;q<m;q++)
                    {
                        int fnl=cur;

                        for(int t=0;t<5;t++)
                        {
                            int x1=p+x_[t];
                            int y1=q+y_[t];

                            if(in(x1,y1)&&abs(x1-i)+abs(y1-j)>=2)
                                fnl=fnl-test(x1,y1);
                        }

                        if(fnl<=1)
                        {
                            swap(inp[i][j],inp[p][q]);

                            int score=fnl;

                            for(int t=0;t<5;t++)
                                score+=test(i+x_[t],j+y_[t]);

                            for(int t=0;t<5;t++)
                            {
                                int x1=p+x_[t];
                                int y1=q+y_[t];

                                if(in(x1,y1)&&abs(x1-i)+abs(y1-j)>=2)
                                    score+=test(x1,y1);
                            }

                            //cout<<i<<" "<<j<<" "<<p<<" "<<q<<" "<<local<<" "<<fnl<<" "<<score<<endl;

                            assert(score>=1);

                            if(score==1)
                            {
                                pair<int,int> alpha={i,j};
                                pair<int,int> beta={p,q};

                                if(alpha>beta)swap(alpha,beta);

                                seen.insert({alpha,beta});
                            }

                            swap(inp[i][j],inp[p][q]);
                        }
                    }
            }
        }

    if(seen.size()==0)printf("2\n");
    else printf("1 %i\n",seen.size());

    return 0;
}