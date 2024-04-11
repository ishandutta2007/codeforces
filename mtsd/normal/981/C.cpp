#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

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
    scanf("%d",&n);
    if(n==2){
        int a;
        rep(i,1){
            cin >> a;
        }
        cout << "Yes"<< endl;
        cout << 1 << endl;
        cout << "1 2" << endl;
    }else{
        vector<vector<int> > g(n);
        rep(i,n-1){
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int cnt = 0;
        int x = 0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(g[i].size()==1){
                v.PB(i);
            }
            if(g[i].size()==2&&cnt==0){
                x = i;
            }
            if(g[i].size()>2){
                x= i;
                cnt++;
            }
        }
        if(cnt>=2){
            cout << "No" << endl;
            return 0;
        }
        printf("Yes\n");
        printf("%d\n",(int)v.size());
        for(auto y:v){
            printf("%d %d\n",x+1,y+1);
        }
    }


    return 0;
}