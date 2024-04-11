#include<bits/stdc++.h>
using namespace std;
const long long int N = 8e5+100;
long long int n;
long long int no = 8e5+1;
int t[2*N]{0};
int combine(int &a,int &b){
    return max(a,b);
}
void build(){
    for(int i=no-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
int query(int l,int r){
    int ret = 0;
    for(l+=no,r+=no;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,t[l++]);
        if(r&1) ret=combine(t[--r],ret);
    }
    return ret;
}
string s;
int arr[200001];
void pre(){}
void solve(){
    cin>>s;n=s.size();
    arr[0]=no/2;
    t[no+no/2]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            arr[i+1]=arr[i]-1;
        }else{
            arr[i+1]=arr[i]+2;
        }
        t[no+arr[i+1]]=i+1;
    }
    build();
    int ans = 0,val=0;
    for(int i=0;i<n;i++){
        int temp = query(arr[i],no+1)-i;
        if(temp>ans){
            ans=temp;
            val=1;
        }else if(ans==temp)
            val++;
    }
    if(ans==0){
        cout<<"No solution"<<"\n";
    }else{
        cout<<ans<<" "<<val<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}