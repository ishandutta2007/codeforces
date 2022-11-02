#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll sum[4001];

ll getsum(int a, int b){
    if (a==0) return sum[b];
    return sum[b]-sum[a-1];
}

map<ll, int> ss;

int main(){
    ll a;
    cin>>a;
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n;i++){
        sum[i]+=(s[i]-'0');
        if (i) sum[i]+=sum[i-1];
    }
    ll as=0;
    ll s0=0;
    for (int i=0;i<n;i++){
        for (int ii=i;ii<n;ii++){
            as++;
            if (getsum(i, ii)<=a){
                ss[getsum(i, ii)]++;
            }
            if (getsum(i, ii)==0){
                s0++;
            }
        }
    }
    ll v=0;
    for (int i=0;i<n;i++){
        for (int ii=i;ii<n;ii++){
            ll su=getsum(i, ii);
            if (su==0&&a==0) v+=as;
            else if (a==0){
                v+=s0;
            }
            else if (su>0&&su<=a){
                if (a%su==0){
                    v+=ss[a/su];
                }
            }
        }
    }
    cout<<v<<endl;
}