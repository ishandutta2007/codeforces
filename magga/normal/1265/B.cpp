#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    vector<long long int> ref[n];
    bool boo[n];
    int ans[n];
    long long int magic=-1;
    long long int lol = 0;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        //ref[i]=0;
        boo[i]=false;
        ans[i]=-5;
        if(arr[i]==1){
            magic=i;
        }
    }
    long long int max=1;
    long long int min=n;
    for(long long int i=magic+1;i<n;i++){
        if(max>arr[i]){
            lol++;
            ref[arr[i]-1].push_back(lol);
            ref[max-1].push_back(lol);
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    max=1;
    for(long long int i=magic-1;i>=0;i--){
        if(max>arr[i]){
            lol++;
            ref[arr[i]-1].push_back(lol);
            ref[max-1].push_back(lol);
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    set<long long int>h;
    for(long long int i=0;i<n;i++){
        if(h.size()==0 && ref[i].size()==0){
            ans[i]=1;
        }else if(h.size()>0 && ref[i].size()==0){
            ans[i]=0;
        }else if(ref[i].size()!=0){
            for(long long int j:ref[i]){
                if(h.find(j)==h.end()){
                    h.insert(j);
                }else{
                    h.erase(j);
                }
            }
            if(h.size()==0){
                ans[i]=1;
            }else{
                ans[i]=0;
            }
        }
    }
    for(long long int i:ans){
        cout<<i;
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}