#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,arr[nmax];
pair<int/*number*/,int/*times*/> help[nmax];
int ID=0;
set< pair<int/*size*/,int/*position*/> > order;
int fenwick[nmax];
int query(int pos)
{
    int ret=0;
    while(pos)
    {
        ret=ret+fenwick[pos];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
int sum(int l,int r)
{
    return query(r)-query(l-1);
}
void update(int pos,int value)
{
    while(pos<=n)
    {
        fenwick[pos]+=value;
        pos=pos+(pos&(-pos));
    }
}
int SZ[nmax];
void prec()
{
    for(int i=1;i<=n;i++)
        if(help[ID].first==arr[i])help[ID].second++;
        else help[++ID]={arr[i],1};

    //cout<<"help: ";for(int i=1;i<=ID;i++)cout<<help[i].first<<" "<<help[i].second<<"   ";cout<<endl;

    for(int i=1;i<=ID;i++)
        {order.insert({help[i].second,-i});SZ[i]=help[i].second;}
    for(int i=1;i<=ID;i++)
        update(i,1);
}
int left_search(int pos)
{
    int ok=0,not_ok=pos;
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;
        if(sum(av,pos))ok=av;
        else not_ok=av;
    }
    return ok==0?-1:ok;
}
int right_search(int pos)
{
    int ok=n+1,not_ok=pos;
    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;
        if(sum(pos,av))ok=av;
        else not_ok=av;
    }
    return (ok>n?-1:ok);
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
prec();
int turns=0;
while(order.size())
{
    set< pair<int/*size*/,int/*position*/> >::iterator it=order.end();
    it--;
    pair<int/*size*/,int/*position*/> now=(*it);
    now.second=-now.second;

    //cout<<now.first<<" "<<now.second<<endl;

    update(now.second,-1);

    int le=left_search(now.second);
    int ri=right_search(now.second);

    //cout<<le<<" "<<ri<<endl;

    if(le!=-1&&ri!=-1&&help[le].first==help[ri].first)
    {
        order.erase({SZ[le],-le});
        order.erase({SZ[ri],-ri});
        SZ[le]+=SZ[ri];
        order.insert({SZ[le],-le});
        update(ri,-1);
    }

    turns++;
    order.erase(it);
}
printf("%i\n",turns);
return 0;
}