#include<bits/stdc++.h>
using namespace std;
long long int parent[200001]{0};
long long int dp[200001]{0};
long long int size1[200001]{0};
long long int find_set(long long int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(long long int v) {
    parent[v] = v;
    size1[v] = 1;
}

void union_sets(long long int a,long long int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size1[a] < size1[b])
            swap(a, b);
        parent[b] = a;
        size1[a] += size1[b];
    }
}
void solve(){
    long long int n,m,a,b;cin>>n>>m;
    for(long long int i=0;i<n;i++){
        make_set(i);
    }
    for(long long int i=0;i<m;i++){
        cin>>a>>b;
        a--;
        b--;
        union_sets(a,b);
        if(dp[min(a,b)]<max(a,b)){
            dp[min(a,b)]=max(a,b);
        }
    }
    long long int ans =0;
    long long int ref = 0;
    long long int too = 0;
    for(long long int i=0;i<n;i++){
        too = dp[i];
        ref = max(i+1,ref);
        for(;ref<=too;ref++){
            if(find_set(i)==find_set(ref)){
                //ref++;
            }else{
                //cout<<ref<<" "<<i<<"\n";
                union_sets(ref,i);
                //ref++;
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
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