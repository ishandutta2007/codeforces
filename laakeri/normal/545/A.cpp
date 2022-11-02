#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int nok[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int a;
            cin>>a;
            if (a==1) nok[i]=1;
            if (a==2) nok[j]=1;
            if (a==3){
                nok[i]=1;
                nok[j]=1;
            }
        }
    }
    vector<int> v;
    for (int i=0;i<n;i++){
        if (nok[i]==0) v.push_back(i+1);
    }
    cout<<v.size()<<endl;
    for (int vv:v){
        cout<<vv<<" ";
    }
}