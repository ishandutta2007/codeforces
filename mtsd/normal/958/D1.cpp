#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n;
    cin >> n;
    map<double,int>mp;
    vector<double>a(n); 
    rep(j,n){
        string s;
        cin >> s;
        int x = 0;
        int p = 0;
        int q = 0;
        int r = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')continue;
            if(s[i]=='+'){
                x = 1;
            }else if(s[i]==')'){
                x = 2;
                continue;
            }else if(s[i]=='/'){
                continue;
            }else if(x==0){
                p *=10;
                p += s[i]-'0';
            }else if(x==1){
                q *=10;
                q += s[i]-'0';
            }else{
                r *=10;
                r += s[i]-'0';
            }
        }
        double z = (double)(p+q)/(double)r;
        a[j] = z;
        mp[z]++;
        
    }
    rep(i,n){
        cout << mp[a[i]] << endl;
    }
    return 0;
}