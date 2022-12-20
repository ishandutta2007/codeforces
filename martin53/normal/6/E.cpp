#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,k;
int h[nmax];
vector< pair<int,int> > outp;
deque< pair<int/*value*/,int/*index*/> > min_deque,max_deque;

void add(int value,int index)
{
    if(min_deque.size()==0)min_deque.push_back({value,index});
    else
    {
        while(min_deque.size()&&min_deque.back().first>=value)min_deque.pop_back();
        min_deque.push_back({value,index});
    }

    if(max_deque.size()==0)max_deque.push_back({value,index});
    else
    {
        while(max_deque.size()&&max_deque.back().first<=value)max_deque.pop_back();
        max_deque.push_back({value,index});
    }

}
void unadd(int index)
{
if(min_deque.front().second==index)min_deque.pop_front();
if(max_deque.front().second==index)max_deque.pop_front();
}
bool can(int a,bool mem)
{
min_deque.clear();
max_deque.clear();
for(int i=1;i<a;i++)
    add(h[i],i);
for(int i=a;i<=n;i++)
{
add(h[i],i);
    if(max_deque.front().first-min_deque.front().first<=k)
    {
        if(mem==0)return 1;
        outp.push_back({i-a+1,i});
    }
unadd(i-a+1);
}
return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>h[i];
int ok=1,not_ok=n+1;
while(not_ok-ok>1)
{
int av=(ok+not_ok)/2;
if(can(av,0))ok=av;
else not_ok=av;
}

cout<<ok;
can(ok,1);
cout<<" "<<outp.size()<<endl;
for(auto k:outp)cout<<k.first<<" "<<k.second<<endl;
return 0;
}