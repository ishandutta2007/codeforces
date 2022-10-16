#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    vector<long long int>grap[n];
    long long int a,b;
    pair<pair<long long int,long long int>,long long int>arr[n];
    for(long long int i=0;i<n;i++){
        cin>>a>>b;
        arr[i].first.first=a;
        arr[i].first.second=b;
        arr[i].second=i;
    }
    sort(arr,arr+n);
    long long int edge=0;
    set<pair<long long int,long long int>>s;
    for(auto i:arr){
        if(edge>=n){
            cout<<"NO"<<"\n";
            return;
        }
        while(s.size()>0 && (*s.begin()).first<i.first.first){
            s.erase(*s.begin());
        }
        for(auto j:s){
            if(j.first<i.first.second){
                grap[i.second].push_back(j.second);
                grap[j.second].push_back(i.second);
                edge++;
            }else{
                break;
            }
        }
        s.insert(make_pair(i.first.second,i.second));
    }
    if(edge!=n-1){
        cout<<"NO"<<"\n";
        return;
    }
    bool flag[n];
    for(long long int i=0;i<n;i++){
        flag[i]=false;
    }
    flag[0]=true;
    long long int visited=1;
    stack<long long int>st;
    st.push(0);
    long long int d;
    while(st.size()!=0){
        d=st.top();
        st.pop();
        for(long long int i:grap[d]){
            if(!flag[i]){
                visited++;
                flag[i]=true;
                st.push(i);
            }
        }
    }
    if(visited==n){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}