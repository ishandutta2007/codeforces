#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <cstdio>
#include <map>
#include <iomanip>
#include <random>

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

vector<int> make_vector(vector<int> d,int n){
    vector<int> a,b(n),c(n);
    int s = d[0]+1;
    
    while(1){
        rep(i,n){
            b[i] = rand()%10000;
            //cout << b[i] << endl;
        }
        int ss  = 0;
        rep(i,n){
            ss += b[i];
        }
        int cc = 0;
        rep(i,n-1){
            c[i] = 1+((s-n)*b[i])/ss;
            cc += c[i];
        }
        c[n-1] = s-cc;
        random_shuffle(c.begin(),c.end());
        vector<int> p;
        rep(i,n){
            rep(j,c[i]){
                p.push_back(d[i]);
            }
        }
        vector<int> q(s);
        q[0] = p[0];
        rep(i,s-1){
            q[i+1] = q[i] + p[i+1];
        }
        if(q[s-1]%2!=0)continue;
        bool flag = 1;
        rep(i,n){
            int xxx = 0;
            for(int j=i+1;j<s;j++){
                xxx += min(p[j],i+1);
            }
            if(q[i] > i*(i+1)+xxx){
                flag = 0;
                break;
            }
        }
        if(flag){
            a = p;
            break;
        }
    }
    return a;
}


int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n)cin >> p[i];
    reverse(p.begin(),p.end());
    vector<int> c = make_vector(p,n);
    // rep(i,c.size()){
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    vector<pair<int,int> >q(c.size());
    rep(i,c.size()){
        q[i] = MP(c[i],i);
    }
    n = q.size();
    vector<pair<int,int> > m;
    while(1){
        sort(q.begin(),q.end(),greater<pair<int,int> >());
        if(q[0].first==0)break;
        int y = q[0].first;
        q[0].first = 0;
        for(int i=1;i<=y;i++){
            q[i].first -=1;
            m.PB(MP(q[0].second,q[i].second));
        }
    }
    printf("%d\n",(int)m.size());
    rep(i,m.size()){
        printf("%d %d\n",m[i].first+1,m[i].second+1);
    }
    return 0;
}