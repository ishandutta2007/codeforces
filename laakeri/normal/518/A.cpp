#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int ok=0;
    for (int i=0;i<n;i++){
        if (a[i]<'z'){
            string c=a;
            c[i]++;
            for (int ii=i+1;ii<n;ii++){
                c[ii]='a';
            }
            if (c<b){
                cout<<c<<endl;
                return 0;
            }
        }
    }
    cout<<"No such string"<<endl;
}