#include<bits/stdc++.h>
using namespace std;
void solve()
{   
    long long int n;cin>>n;
    set<long long int>arr[n];
    //pair<long long int,long long int>p;
    //for(long long int i=0;i<n;i++){arr[i]=p;}
    long long int prev,next,curr,start;
    start=-1;
    for(long long int i=0;i<n-2;i++){
        cin>>prev;cin>>curr;cin>>next;
        prev--;
        curr--;
        next--;
        arr[curr].insert(prev);
        arr[curr].insert(next);
        arr[next].insert(prev);
        arr[next].insert(curr);
        arr[prev].insert(curr);
        arr[prev].insert(next);
    }
    for(long long int i=0;i<n;i++){
        if(arr[i].size()==2){
            start=i;
            break;
        }
    }
    long long int ans[n];
    ans[0]=start;
    set<long long int>inc;
    for(long long int i:arr[start]){
        if(arr[i].size()==3){
            ans[1]=i;
            inc.insert(i);
        }
    }
    inc.insert(start);
    long long int cu = 2;
    while(inc.size()!=n){
        for(long long int i:arr[ans[cu-1]]){
            if(inc.find(i)==inc.end() && arr[i].find(ans[cu-2])!=arr[i].end()){
                ans[cu]=i;
                inc.insert(i);
                cu++;
            }
        }
    }
    for(long long int i:ans){
        cout<<i+1<<" ";
    }
    cout<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}