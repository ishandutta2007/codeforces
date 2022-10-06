#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>
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

int main(){
    int n,x1,x2;
    scanf("%d %d %d",&n,&x1,&x2);
    vector<pair<int,int> > v;
    map<int,int> mp;
    rep(i,n){
        int tmp;
        scanf("%d",&tmp);
        mp[tmp]++;
        v.PB(MP(tmp,i+1));
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    vector<pair<int,int> > s;
    for(auto x:mp){
        s.PB(MP(x.first,x.second));
    }
    for(int i=s.size()-1;i>=1;i--){
        s[i-1].second += s[i].second;
    }
    int xx = s.size();
    vector<int> a(xx),b(xx),c(xx),ba(xx),ca(xx);
    rep(i,xx){
        a[i] = s[i].second;
    }
    rep(i,xx){
        b[i] = (x1+s[i].first-1)/s[i].first;
    }
    rep(i,xx){
        c[i] = (x2+s[i].first-1)/s[i].first;
    }
    rep(i,xx){
        ba[i] = a[i]-b[i];
    }
    rep(i,xx){
        ca[i] = a[i]-c[i];
    }
    rep(i,xx-1){
        ba[i+1] = max(ba[i],ba[i+1]);
    }
    rep(i,xx-1){
        ca[i+1] = max(ca[i],ca[i+1]);
    }
    bool flag = 0;
    bool fflag = 0;
    int val1,val2,cnt1,cnt2;
    rep(i,xx){
        if(a[i]>=c[i]&&ba[i]>=c[i]){
            flag = 1;
            fflag = 1;
            val2 = s[i].first;
            cnt2 = c[i];
            rep(j,xx){
                if(ba[j]>=c[i]){
                    val1 = s[j].first;
                    cnt1 = b[j];
                    break;
                }
            }
            break;
        }
    }
    if(!flag){
    rep(i,xx){
        if(a[i]>=b[i]&&ca[i]>=b[i]){
            flag = 1;
            val1 = s[i].first;
            cnt1 = b[i];
            rep(j,xx){
                if(ca[j]>=b[i]){
                    val2 = s[j].first;
                    cnt2 = c[j];
                    break;
                }
            }
            break;
        }
    }
    }
    //cout << val1 << " " << val2 << endl;
    if(!flag){
        cout <<"No" << endl;
    }else{
        cout << "Yes" << endl;
        vector<int> ans_b,ans_c;
        if(fflag){
            for(int i=0;i<cnt2;i++){
                ans_c.push_back(v[i].second);
            }
            for(int i=cnt2;i<cnt2+cnt1;i++){
                ans_b.push_back(v[i].second);
            }
        }else{
            for(int i=0;i<cnt1;i++){
                ans_b.push_back(v[i].second);
            }
            for(int i=cnt1;i<cnt2+cnt1;i++){
                ans_c.push_back(v[i].second);
            }
        }
        cout << ans_b.size() << " " << ans_c.size() << endl;
        rep(i,ans_b.size()){
            if(i!=ans_b.size()-1){
                printf("%d ",ans_b[i]);
            }else{
                printf("%d",ans_b[i]);
            }
        }
        printf("\n");
        rep(i,ans_c.size()){
            if(i!=ans_c.size()-1){
                printf("%d ",ans_c[i]);
            }else{
                printf("%d",ans_c[i]);
            }
        }
        printf("\n");
    }
    

    return 0;
}