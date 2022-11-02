#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ispal(int x){
    vector<int> a;
    while (x){
        a.push_back(x%10);
        x/=10;
    }
    for (int i=0;i<(int)a.size();i++){
        if (a[i]!=a[(int)a.size()-1-i]){
            return 0;
        }
    }
    return 1;
}

int s[10101010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m=2e6;
    for (int i=2;i<m;i++){
        if (s[i]==0){
            for (int j=i*2;j<m;j+=i){
                s[j]=1;
            }
        }
    }
    s[1]=1;
    int pa=0;
    int pr=0;
    int p,q;
    cin>>p>>q;
    int ma=0;
    for (int i=1;i<m;i++){
        if (ispal(i)){
            pa++;
        }
        if (s[i]==0){
            pr++;
        }
        if (q*pr<=p*pa){
            ma=max(ma, i);
        }
    }
    cout<<ma<<endl;
}