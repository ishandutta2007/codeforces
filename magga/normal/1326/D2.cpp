#include<bits/stdc++.h>
using namespace std;
void pre(){}

void solve(){
    string s1;cin>>s1;
    long long int n=s1.size();
    long long int start = 0;
    long long int j = 0;
    while(2*j<n && s1[j]==s1[n-1-j]){
        j++;
    }
    start=j;
    if(2*j>=n){
        cout<<s1<<"\n";
        return;
    }    
    string s;
    for(long long int i = j;i<=n-j-1;i++){
        s+=s1[i];
    }
    n = s.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    long long int key = -1;
    long long int m = 0;
    long long int type = 0;
    for(long long int i=0;i<n;i++){
        if(i+1==d1[i]){
            if(d1[i]*2-1>m){
                m = d1[i]*2-1;
                type = 1; 
                key = i;
            } 
        }
        if(n-d1[i]==i){
            if(2*d1[i]-1>m){
                m = 2*d1[i]-1;
                type = 2;
                key=i; 
            } 
        }
    }
    for(long long int i=0;i<n;i++){
        if(d2[i]==i){
            if(d2[i]*2>m){
                m = d2[i]*2;
                type = 3;
                key=i; 
            } 
        }
        if(d2[i]+i==n){
            if(d2[i]*2>m){
                m = d2[i]*2;
                type = 4;
                key=i; 
            } 
        }
    }
    if(type==1 || type==3){
        for(long long int i=0;i<start;i++){
            cout<<s1[i];
        }
        for(long long int i=0;i<m;i++){
            cout<<s[i];
        }
        for(long long int i=s1.size()-start;i<s1.size();i++){
            cout<<s1[i];
        }
        cout<<"\n";
    }
    if(type==2 || type==4){
        for(long long int i=0;i<start;i++){
            cout<<s1[i];
        }
        for(long long int i=n-m;i<n;i++){
            cout<<s[i];
        }
        for(long long int i=s1.size()-start;i<s1.size();i++){
            cout<<s1[i];
        }
        cout<<"\n";
    }
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