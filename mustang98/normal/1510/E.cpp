//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
 
#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif
 
#define F first
#define S second
#define MP make_pair
#define PB push_back
 
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
 
const int max_n = -1, inf = 1000111222;
const ll base = 1e8;
 
map<int,map<pair<ll,ll>,int>> keks;
const bool debug=1;
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    int n;
    ld x_ld,y_ld;
    cin>>n>>x_ld>>y_ld;
    int mid=n/2;
    for (int mask=0;mask<(1ll<<mid);mask++){
//        cout<<"new mask"<<"\n";
        int bal=0;
        bool ok=1;
        ld sum_x_ld=0,sum_y_ld=0;
        ll doubled_s=0;
        for (int i=0;i<mid;i++){
            if (mask&(1ll<<i)){
                {
                    // rect
                    ld cur_center_x = i + 0.5;
                    ld cur_center_y = bal / 2.0;
//                    cout<<"rect1 :: "<<cur_center_x<<" "<<cur_center_y<<"\n";
                    sum_x_ld+=cur_center_x*2*bal;
                    sum_y_ld+=cur_center_y*2*bal;
                    doubled_s+=2*bal;
                }
 
                {
                    // triangle
                    ld cur_center_x = (i + i+1 + i+1)/3.0;
                    ld cur_center_y = (bal + bal + bal+1)/3.0;
//                    cout<<"triangle1 :: "<<cur_center_x<<" "<<cur_center_y<<"\n";
                    sum_x_ld+=cur_center_x*1;
                    sum_y_ld+=cur_center_y*1;
                    doubled_s+=1;
                }
 
                bal++;
            }
            else{
                {
                    // rect
                    ld cur_center_x = i + 0.5;
                    ld cur_center_y = (bal-1) / 2.0;
//                    cout<<"rect2 :: "<<cur_center_x<<" "<<cur_center_y<<"\n";
                    sum_x_ld+=cur_center_x*2*(bal-1);
                    sum_y_ld+=cur_center_y*2*(bal-1);
                    doubled_s+=2*(bal-1);
                }
 
                {
                    // triangle
                    ld cur_center_x = (i + i + i+1)/3.0;
                    ld cur_center_y = (bal + bal-1 + bal-1)/3.0;
//                    cout<<"triangle2 :: "<<cur_center_x<<" "<<cur_center_y<<"\n";
                    sum_x_ld+=cur_center_x*1;
                    sum_y_ld+=cur_center_y*1;
                    doubled_s+=1;
                }
 
                bal--;
            }
 
            if (bal<0){
                ok=0;
            }
        }
        if (ok){
            ll value_x = round((sum_x_ld-x_ld*doubled_s)*base);
            ll value_y = round((sum_y_ld-y_ld*doubled_s)*base);
            for (int dx=-1;dx<=1;dx++){
                for (int dy=-1;dy<=1;dy++){
                    keks[bal][mp(value_x+dx,value_y+dy)]=mask;
                }
            }
//            if (debug){
//                cout<<"found something in :: ";
//                for (int k=0;k<mid;k++){
//                    if (mask&(1ll<<k)){
//                        cout<<"(";
//                    }
//                    else{
//                        cout<<")";
//                    }
//                }
//                cout<<"\n";
//                cout<<"sum_x_int doubled_s :: "<<sum_x_int<<" "<<doubled_s<<"\n";
//                cout<<"sum_y_int doubled_s :: "<<sum_y_int<<" "<<doubled_s<<"\n";
//                cout<<bal<<" "<<sum_x_int-x_int*doubled_s<<" "<<sum_y_int-y_int*doubled_s<<"\n";
//            }
        }
    }
    for (int mask=0;mask<(1ll<<mid);mask++){
//        cout<<"new mask"<<"\n";
        int bal=0;
        for (int i=0;i<mid;i++){
            if (mask&(1ll<<i)) {
                bal++;
            }
            else{
                bal--;
            }
        }
        bal=-bal;
        int start_bal=bal;
        if (start_bal<0){
            continue;
        }
 
        bool ok=1;
        ld sum_x_ld=0,sum_y_ld=0;
        ll doubled_s=0;
        for (int i=mid;i<n;i++){
            if (mask&(1ll<<(i-mid))){
                {
                    // rect
                    ld cur_center_x = i + 0.5;
                    ld cur_center_y = bal / 2.0;
//                    cout<<"rect1 :: "<<cur_center_x<<" "<<cur_center_y<<"\n";
                    sum_x_ld+=cur_center_x*2*bal;
                    sum_y_ld+=cur_center_y*2*bal;
                    doubled_s+=2*bal;
                }
 
                {
                    // triangle
                    ld cur_center_x = (i + i+1 + i+1)/3.0;
                    ld cur_center_y = (bal + bal + bal+1)/3.0;
//                    cout<<"triangle1 :: "<<cur_center_x<<" "<<cur_center_y<<"\n";
                    sum_x_ld+=cur_center_x*1;
                    sum_y_ld+=cur_center_y*1;
                    doubled_s+=1;
                }
 
                bal++;
            }
            else{
                {
                    // rect
                    ld cur_center_x = i + 0.5;
                    ld cur_center_y = (bal-1) / 2.0;
//                    cout<<"rect2 :: "<<cur_center_x<<" "<<cur_center_y<<"\n";
                    sum_x_ld+=cur_center_x*2*(bal-1);
                    sum_y_ld+=cur_center_y*2*(bal-1);
                    doubled_s+=2*(bal-1);
                }
 
                {
                    // triangle
                    ld cur_center_x = (i + i + i+1)/3.0;
                    ld cur_center_y = (bal + bal-1 + bal-1)/3.0;
//                    cout<<"triangle2 :: "<<cur_center_x<<" "<<cur_center_y<<"\n";
                    sum_x_ld+=cur_center_x*1;
                    sum_y_ld+=cur_center_y*1;
                    doubled_s+=1;
                }
 
                bal--;
            }
 
            if (bal<0){
                ok=0;
            }
        }
        if (ok){
            ll value_x = round((sum_x_ld-x_ld*doubled_s)*base);
            ll value_y = round((sum_y_ld-y_ld*doubled_s)*base);
//            if (debug){
//                cout<<"found something right part in :: ";
//                for (int k=0;k<mid;k++){
//                    if (mask&(1ll<<k)){
//                        cout<<"(";
//                    }
//                    else{
//                        cout<<")";
//                    }
//                }
//                cout<<"\n";
//                cout<<"\n";
//                cout<<"sum_x_int doubled_s :: "<<sum_x_int<<" "<<doubled_s<<"\n";
//                cout<<"sum_y_int doubled_s :: "<<sum_y_int<<" "<<doubled_s<<"\n";
//                cout<<bal<<" "<<sum_x_int-x_int*doubled_s<<" "<<sum_y_int-y_int*doubled_s<<"\n";
//            }
            for (int dx=-1;dx<=1;dx++){
                for (int dy=-1;dy<=1;dy++){
                    if (keks[start_bal].count(mp(-value_x+dx,-value_y+dy))){
                        ll mask1=keks[start_bal][mp(-value_x+dx,-value_y+dy)];
                        ll mask2=mask;
                        ll res_mask=mask1|(mask2<<mid);
                        for (int k=0;k<n;k++){
                            if (res_mask&(1ll<<k)){
                                cout<<"(";
                            }
                            else{
                                cout<<")";
                            }
                        }
                        cout<<"\n";
                        return 0;
                    }
                }
            }
        }
    }
    assert(0);
}