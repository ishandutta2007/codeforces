#include <iostream>
#include <map>
#include <vector>
#define F first
#define S second

using namespace std;

typedef long long ll;

map<int, ll> lol[100002];

map<int, ll> v;

int gcd(int a, int b){
    if (a%b==0) return b;
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        for (auto asd:lol[i]){
            int g=gcd(asd.F, a);
            lol[i+1][g]+=asd.S;
            v[g]+=asd.S;
        }
        lol[i+1][a]++;
        v[a]++;
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int a;
        cin>>a;
        cout<<v[a]<<'\n';
    }
}