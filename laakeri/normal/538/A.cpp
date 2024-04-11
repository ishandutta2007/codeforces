#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string cf="CODEFORCES";
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n;i++){
        for (int ii=i-1;ii<n;ii++){
            string ss="";
            for (int iii=0;iii<n;iii++){
                if (iii<i||iii>ii){
                    ss+=s[iii];
                }
            }
            if (ss==cf){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}