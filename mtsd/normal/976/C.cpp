#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

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

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.first.first<b.first.first){
        return true;
    }
    if(a.first.first>b.first.first){
        return false;
    }
    if(a.first.second <= b.first.second){
        return false;
    }else{
        return true;
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int> > v;
    rep(i,n){
        int a,b;
        scanf("%d %d",&a,&b);
        v.PB(MP(MP(a,b),i+1));
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n-1;i++){
        if(v[i].first.second >= v[i+1].first.second){
            cout << v[i+1].second << " " <<  v[i].second << endl; 
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}