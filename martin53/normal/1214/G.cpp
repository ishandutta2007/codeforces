#include<bits/stdc++.h>
using namespace std;
const int nmax=2042;
int n,m,q;
bitset<nmax> seen[nmax],other;

int nxt[nmax],prv[nmax];

set<int> correct;

bitset<nmax> bits[nmax];

set< pair<int/*ones*/,int/*number*/> > there;

int current_ones[nmax];

bool valid(int pos)
{
    return 1<=pos&&pos<=n;
}
void to_remove(int smaller,int bigger)
{
    if(valid(smaller)==0||valid(bigger)==0)return;

    //cout<<"to_remove "<<smaller<<" "<<bigger<<endl;
    //while(seen[smaller].count()>seen[bigger].count());

    if((seen[bigger]&seen[smaller])!=seen[smaller])correct.erase(smaller);
}

void to_add(int smaller,int bigger)
{
    if(valid(smaller)==0||valid(bigger)==0)return;

    //cout<<"to_add "<<smaller<<" "<<bigger<<endl;
    //while(seen[smaller].count()>seen[bigger].count());

    if((seen[bigger]&seen[smaller])!=seen[smaller])correct.insert(smaller);
}

int main()
{
    scanf("%i%i%i",&n,&m,&q);

    for(int i=0;i<=n+1;i++)nxt[i]=i+1;
    for(int i=n+1;i>=0;i--)prv[i]=i-1;

    for(int i=1;i<=m;i++)
    {
        bits[i]=bits[i-1];
        bits[i][i]=1;
    }

    current_ones[0]=-1;
    current_ones[n+1]=m+1;

    there.insert({-1,0});
    there.insert({m+1,n+1});
    for(int i=1;i<=n;i++)there.insert({0,i});

    int pos,l,r;
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i%i",&pos,&l,&r);
        there.erase({current_ones[pos],pos});

        to_remove(prv[pos],pos);
        to_remove(pos,nxt[pos]);
        to_add(prv[pos],nxt[pos]);
        nxt[prv[pos]]=nxt[pos];
        prv[nxt[pos]]=prv[pos];

        seen[pos]=seen[pos]^bits[l-1]^bits[r];

        /*
        cout<<"prv: ";for(int i=0;i<=n+1;i++)cout<<prv[i]<<" ";cout<<endl;
        cout<<"nxt: ";for(int i=0;i<=n+1;i++)cout<<nxt[i]<<" ";cout<<endl;
        */

        current_ones[pos]=seen[pos].count();
        set< pair<int/*size*/,int/*ones*/> >::iterator it=there.lower_bound(make_pair(current_ones[pos]+1,0));

        int add_before=(*it).second;
        while(current_ones[add_before]==current_ones[prv[add_before]])add_before=prv[add_before];

        there.insert({current_ones[pos],pos});

        //cout<<"pos= "<<pos<<" add_before= "<<add_before<<endl;

        to_remove(prv[add_before],add_before);
        to_add(prv[add_before],pos);
        to_add(pos,add_before);

        prv[pos]=prv[add_before];
        nxt[pos]=add_before;

        nxt[prv[add_before]]=pos;
        prv[add_before]=pos;

        if(correct.size())
        {
            int row=(*correct.begin());
            int y1=(seen[row]&(~seen[nxt[row]]))._Find_first();
            int y2=((~seen[row])&seen[nxt[row]])._Find_first();
            if(y1>y2)swap(y1,y2);

            int x1=row;
            int x2=nxt[row];
            if(x1>x2)swap(x1,x2);

            printf("%i %i %i %i\n",x1,y1,x2,y2);
        }
        else printf("-1\n");
        /*
        cout<<"seen: "<<endl;
        for(int p=1;p<=n;p++)
        {
            for(int q=1;q<=m;q++)cout<<seen[p][q];
            cout<<endl;
        }

        cout<<"prv: ";for(int i=0;i<=n+1;i++)cout<<prv[i]<<" ";cout<<endl;
        cout<<"nxt: ";for(int i=0;i<=n+1;i++)cout<<nxt[i]<<" ";cout<<endl;
        cout<<"there: ";for(auto k:there)cout<<k.first<<" "<<k.second<<" \t ";cout<<endl;

        cout<<"---"<<endl;
        */
    }
    return 0;
}