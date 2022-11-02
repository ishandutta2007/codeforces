#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

ld ddk[500001];

int main(){
    string s;
    cin>>s;
    int n=s.size();
    ld k=0;
    ld dk=0;
    for (int i=1;i<=n;i++){
        dk+=(ld)1/(ld)i;

        ddk[min(i, n-i+1)]-=(ld)1/(ld)i;
        //cout<<i<<" "<<min(i, n-i+1)<<endl;
        ddk[max(i, n-i+1)]-=(ld)1/(ld)i;
    }
    ld v=0;
    for (int i=0;i<n;i++){
        dk+=ddk[i];
        k+=dk;
        //cout<<k<<" "<<dk<<endl;
        if (s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y'){
            v+=k;
        }
    }
    cout<<setprecision(15)<<v<<endl;
}