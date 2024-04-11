#include <bits/stdc++.h>    
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>       //                      
#define endl "\n"                               //                 
#define F first                                 //                         
#define S second                            //                           
#define For(i,n) for(int i=0 ;i<n;i++)      //                         
#define cin(v,n) For(i,n) cin>>v[i]           //                      
#define Cin    int n ; cin>>n ; int arr[n] ; cin(arr,n) ; 
#define Cin2     LL arr2[n] ; cin(arr2,n) ; 
#define r0 return 0 
#define B begin()
#define E end()
#define RB rbegin()
#define RE rend()
#define Back(s) *s.rbegin()
#define Front(s) *s.begin()
#define PF(x) push_front(x)
#define PB(x) push_back(x)
#define POF pop_front()
#define POB pop_back()
#define Digits(n) (n==0?1:(int)log10(n)+1)
#define Bits(n) (int)log2(n)+1
#define pof(n) ((n&(n-1))==0)
#define smaller(n) order_of_key(n)  
#define bigger(cont , n , x) ( (n) - cont.smaller( x + 1) )
// #define bigger(cont , x) distance(cont.upper_bound(x) , cont.E)
#define At(n) find_by_order(n) 
#define Idx(cont , x) (int)( L(ms)-(distance(cont.lower_bound(x), cont.E))) // linear time for set... 
#define Sigma(n) (n%2=0?(n/2)*(n+1) :(n+1)/2*n )
#define Modx(a,b,c) ((a%c)*(b%c))%c 
#define Modp(a,b,c) ((a%c)+(b%c))%c 
#define uniq(x)   sort(All(x)); x.erase(unique(All(x)),x.E)
#define L(s) (int) s.size()    //       //
#define IDX(fnd,s) fnd-s.B    //       //
#define MAX INT_MAX          //                 //
#define MIN INT_MIN         //          ++         //
#define uMAX 0xffffffff
#define LA(a) (int)(sizeof(a)/sizeof(a[0]))  
#define full(x) !(x.empty()) 
#define All(v) v.B,v.E    
#define Allr(v) v.rbegin(),v.rend()    
#define getName(x)  #x
#define debug(x) cout<<getName(x)<<" = "<<x<<endl
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
//SORT SECOND(non decreasing) IN NONDECREASING AND IF THE SECOND IS EQUAL SORT ALSO BY FIRST
#define lambda  [](const Pair &x, const Pair &y) {if (x.second != y.second) {return x.second > y.second;} return x.first > y.first;}
//sort by first in greater order and if first = firs sort second by greater
#define lambdaSTEV  [](const pair< pair<ll , string >,vector<ll> &x, const pair< pair<ll , string >,vector<ll> &y) {if (x.F.F != y.F.F) {return x.F.F > y.F.F;} return x.F.S < y.F.S;}
#define Mo_Salah cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define oSet tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define oMap tree<int, int ,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// lower_bound and upper_bound work oppositely
#define oMultiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
#define tests int t  ; cin >> t  ; while(t--)
 void judge (){
      #ifndef ONLINE_JUDGE 
      freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);  
      #endif
      }
using namespace std ;
using namespace __gnu_pbds;
typedef vector<int> VI ;
typedef vector<long long> VL ;
typedef long long ll ;
typedef pair<ll,ll> Pair ;
const int N = 200005 ;
const int MOD  = 1e9+7 ;
int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int knightX[]  = { 2, 1, -1, -2, -2, -1, 1, 2 };
int knightY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 int n , m , components  , k ;   
 bool f ; 
bool Salka(int x, int y) { return x > 0 && y > 0 && x <= n && y <= m; } // 1 based
template <typename T1 , typename T2>
void dabt_el_masna3(T1 &v , T2 &v2){
    v =T1(n+1) ; 
    v2 =T2(n+1) ; 
}

                                /*     You just keep pushing. You just keep pushing.  
                                           I made every mistake that could be made.   
                                                But I just kept pushing.           
                                                      Ren Descartes              */

                        /*                         Steven's Golden Rules 
                                             if you feel so dumb you didnt work enough
                                         give it more time more effort you will be better 
                                         if it gives WA that means you will learn something 
         every problem either teach you something or make you better in something other than that you didnt realy solve it .  */
                                            
                                            main (){
                                                Mo_Salah ; 
                                                judge() ; 
                                                cin  >> n  ; 
                                                set<Pair> st1  ,st2  , st3;
                                                string s1(n , '0') , s2(n , '0') ; 
                                                For(i , n){
                                                    int x , y ; cin >>  x >> y ; 
                                                    st1.insert({x , i});
                                                    st2.insert({y , i});
                                                    st3.insert({x , i});
                                                    st3.insert({y , i});
                                                } 
                                                set<Pair>::iterator it = st3.begin();
                                                For(i , n){
                                                    if(st1.find(*it)!=st1.E)
                                                        s1[it->S] ='1' ; 
                                                    else 
                                                        s2[it->S] ='1' ; 
                                                    it++;
                                                }
                                                for(int i =0 ; i < n / 2 ; i++){
                                                    s1[i] ='1' ; 
                                                    s2[i] ='1' ; 
                                                }
                                                cout<<s1<<endl<<s2 ; 
                                                
                                }