#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,l;cin>>n>>l;
    bool visited[n];
    for(long long int i=0;i<n;i++){
        visited[i]=false;
    }
    set<long long int>s;
    set<long long int>p;
    for(long long int i=0;i<n;i++){
        s.insert(i);
    }
    long long int ans = -1;
    set<long long int>arr[n];
    long long int a,b;
    for(long long int i=0;i<l;i++){
        cin>>a>>b;
        a--;
        b--;
        arr[a].insert(b);
        arr[b].insert(a);
    }
    for(long long int i=0;i<n;i++){
        if(!visited[i]){
            ans++;
            visited[i]=true;
            stack<long long int> dfs;
            dfs.push(i);
            s.erase(i);
            while(dfs.size()!=0){
                long long int j = dfs.top();
                dfs.pop();
                p=s;
                for(long long int k:p){
                    if(arr[j].find(k)==arr[j].end()){
                        dfs.push(k);
                        visited[k]=true;
                        s.erase(k);
                    }
                    if(s.size()==0){
                        break;
                    }
                }
            }
        }    
    }
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}