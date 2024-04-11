#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    string s;cin>>s;
    long long int ma = 1;
    for(long long int i=0;i<n-1;i++){
        if(s[i]=='<'){ma++;}
    }
    long long int m1[n];
    long long int m2[n];
    long long int curr1 = n-ma+1;
    long long int curr2 = n-ma+1;
    m1[0]=curr1;
    for(long long int i=1;i<n;i++){
        if(s[i-1]=='>'){
            curr1--;
            m1[i]=curr1;
        }else{
            curr2++;
            m1[i]=curr2;
        }
    }
    curr1 = n-ma+1;
    curr2 = n+1;
    long long int ref = 0;
    for(long long int i=1;i<n;i++){
        if(s[i-1]=='>'){
            curr1--;
            m2[i]=curr1;
        }else{
            ref=0;
            long long int j = i;
            while(j<n && s[j-1]=='<'){
                ref++;
                j++;
            }
            curr2-=ref;
            long long int ruf = 0;
            long long int pro = 0;
            for(;pro<ref && i<n;++pro){
                m2[i]=curr2+ruf;
                i++;
                ruf++;
            }
            i--;
        }
    }
    set<long long int>s1;
    for(long long int i=1;i<=n;i++){
        s1.insert(i);
    }
    for(long long int i=1;i<n;i++){
        s1.erase(m2[i]);
    }
    m2[0]=*s1.begin();
    for(long long int i:m2){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(long long int i:m1){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}