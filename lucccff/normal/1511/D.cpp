#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    cin>>n>>k;
    while(n>0) {
        for(i=0;i<k;i++) {
            cout<<(char)(i+'a');
            n--;
            if (n==0) break; 
            for(j=i+1;j<k;j++) {
                cout<<(char)(i+'a');
                n--;
                if (n==0) break; 
                cout<<(char)(j+'a');
                n--;
                if (n==0) break; 
            }
            if (n==0) break; 
        }
    }
    return 0;
}