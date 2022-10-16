#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,k;cin>>n>>k;
    long long int arr[200002]{0};
    vector<tuple<long long int,long long int,long long int>>v;
    priority_queue<pair<long long int,long long int>>ends;
    pair<long long int,long long int>p;
    long long int a,b;
    for(long long int i=0;i<n;i++){
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
        v.push_back(make_tuple(a,b,i+1));
    }
    vector<long long int>indexes;
    sort(v.begin(),v.end());
    long long int change = 0;
    long long int j=0;
    long long int ans =0;
    for(long long int i=0;i<200002;i++){
        
        while(j<n && get<0>(v[j])<=i){
            p.first=get<1>(v[j]);
            p.second=get<2>(v[j]);
            //cout<<p.first<<" "<<p.second<<endl;
            ends.push(p);
            j++;
        }
        change+=arr[i];
        while(change>k){
            p = ends.top();
            //cout<<p.second<<" "<<(*(ends.begin()++)).second<<"\n";
            ans++;
            ends.pop();
            arr[p.first+1]++;
            indexes.push_back(p.second);
            change--;
        }
        
    }
    cout<<ans<<"\n";
    for(long long int i:indexes){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1 ;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}