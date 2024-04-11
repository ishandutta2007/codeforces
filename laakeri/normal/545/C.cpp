#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int x[101010];
int h[101010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> ccs;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x[i]>>h[i];
    }
    int lo=-2e9;
    int v=0;
    for (int i=0;i<n;i++){
        if (x[i]-h[i]>lo){
            v++;
            lo=x[i];
        }
        else if(i+1==n||x[i]+h[i]<x[i+1]){
            v++;
            lo=x[i]+h[i];
        }
        else{
            lo=x[i];
        }
    }
    cout<<v<<endl;
}