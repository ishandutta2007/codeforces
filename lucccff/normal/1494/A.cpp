#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,a,b,c,f;
    string s;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>s;
        l=s.length();
        f=0;
        if (s[0]=='A') {
            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k++;
                if (s[j]=='B') k--;
                if (s[j]=='C') k--;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }
            
            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k++;
                if (s[j]=='B') k++;
                if (s[j]=='C') k--;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }

            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k++;
                if (s[j]=='B') k--;
                if (s[j]=='C') k++;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }
            if (f) {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

        if (s[0]=='B') {
            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k--;
                if (s[j]=='B') k++;
                if (s[j]=='C') k--;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }
            
            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k++;
                if (s[j]=='B') k++;
                if (s[j]=='C') k--;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }

            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k--;
                if (s[j]=='B') k++;
                if (s[j]=='C') k++;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }
            if (f) {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        
        if (s[0]=='C') {
            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k--;
                if (s[j]=='B') k--;
                if (s[j]=='C') k++;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }
            
            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k++;
                if (s[j]=='B') k--;
                if (s[j]=='C') k++;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }

            k=1;
            for(j=1;j<l;j++){
                if (s[j]=='A') k--;
                if (s[j]=='B') k++;
                if (s[j]=='C') k++;
                if (k<0) break;
            }
            if (k==0) {
                f=1;
            }
            if (f) {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    
    return 0;
}