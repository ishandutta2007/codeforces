#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    
    mt19937 mt{};
    uniform_real_distribution<double> dist{0, 1};
    rep(zz,m){
        ll mx = *max_element(a.begin(),a.end());
        
        string s;
        cin >> s;
        double p = 0;
        double q = 0;
        rep(i,n){
            if(s[i]=='0'){
                if(a[i]-mx >= -20)p += pow(1.666,a[i]-mx);
            }else{
                if(a[i]-mx >= -20)q += pow(1.666,a[i]-mx);
            }
        }
        double prob = dist(mt);
        if(prob < (double)(p)/(double)(p+q)){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
        int k;
        cin >> k;
        rep(i,n){
            if(s[i]==(char)('0'+k)){
                a[i]++;
            }
        }
    }
 
 
    return 0;
}