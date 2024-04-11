#include <bits/stdc++.h> //Stack size ~2'000'000(x4)
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = rbegin(arr)+(plus); x != rend(arr); ++x)
#define PRINT(arr) {copy(begin((arr)), end((arr)), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';exit(0);} //print s_ and terminate program
#define CONT(s_) {cout<<s_<<'\n';continue;} //print s_ and continue;
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 2139062143 //127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

inline bool isnum(string &s){
    FORR(i,s)
        if(!isdigit(i))
            return false;
    return true;
}

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<pair<string,string> > vec;
    int n;
    sc(n);
    int arr[n+1]; //1 -> exam, 2 -> test
    memset(arr,0,sizeof arr);
    vector<string> exam;
    vector<string> test;
    string str;
    int tmp;
    int examcnt = 0;
    vi examintest,testinexam;
    FOR(i,0,n){
        getstr(str); sc(tmp);
        if(tmp){
            ++examcnt;
            if(isnum(str) && to_string(stoi(str)) == str){
                int in = stoi(str);
                if(in <= n && in >= 1){
                    arr[in] = 1;
                }
                else
                    exam.pb(str);
            }
            else
                exam.pb(str);
        }
        else{
            if(isnum(str) && to_string(stoi(str)) == str){
                int in = stoi(str);
                if(in <= n && in >= 1){
                    arr[in] = 2;
                }
                else
                    test.pb(str);
            }
            else
                test.pb(str);
        }
    }
    vi freeexam,freetest;
    FORE(i,1,examcnt){
        if(!arr[i])
            freeexam.pb(i);
        else if(arr[i] == 2)
            testinexam.pb(i);
    }
    FORE(i,examcnt+1,n){
        if(!arr[i])
            freetest.pb(i);
        else if(arr[i] == 1)
            examintest.pb(i);
    }
    if((examintest.size() || testinexam.size()) && (test.empty() && exam.empty())){
        string nazwa;
        FOR(i,0,6){
            nazwa.pb(char((rand() % 26) + 97));
        }
        test.pb(nazwa);
        arr[testinexam.back()] = 0;
        freeexam.pb(testinexam.back());
        /* cout << "move " << testinexam.back() << ' ' << nazwa << '\n'; */
        vec.pb({to_string(testinexam.back()),nazwa});
        testinexam.pop_back();
    }
    /* FORR(i,arr) */
    /*     cout << i; */
    /* cout << "\n\n"; */
    /* cout.flush(); */
    /* bool f = 1; */
    /* FORE(i,1,examcnt){ */
    /*     if(arr[i] != 2){ */
    /*         f = 0; break; */
    /*     } */
    /* } */
    /* if(f){ */
    /*     FORE(i,examcnt+1,n){ */
    /*         if(arr[i] != 1){ */
    /*             f = 0; break; */
    /*         } */
    /*     } */
    /*     if(f){ */
    /*         string nazwa; */
    /*         FOR(i,0,6){ */
    /*             nazwa.pb(char((rand() % 26) + 97)); */
    /*         } */
    /*         test.pb(nazwa); */
    /*         arr[1] = 0; */
    /*         freeexam.pb(1); */
    /*         cout << "move " << 1 << ' ' << nazwa << '\n'; */
    /*     } */
    /* } */
    /* whatis(freeexam) */
    /* whatis(freetest) */
    /* whatis(testinexam) */
    /* whatis(examintest) */
    /*     FORR(i,arr) */
    /*         cout << i; */
    /*     cout << '\n'; */
    /*     cout.flush(); */
    while(examintest.size()){
        if(!freeexam.empty()){
            arr[freeexam.back()] = 1;
            /* cout << "move " << examintest.back() << ' ' << freeexam.back() << '\n'; */
            vec.pb({to_string(examintest.back()),to_string(freeexam.back())});
            arr[examintest.back()] = 0;
            freetest.pb(examintest.back());
            freeexam.pop_back();
            examintest.pop_back();
            /* vec.pb({to_string(testinexam.back()),nazwa}); */
        }
        else{
            arr[examintest.back()] = 0;
            arr[freetest.back()] = 2;
            /* cout << "move " << testinexam.back() << ' ' << freetest.back() << '\n'; */
            vec.pb({to_string(testinexam.back()),to_string(freetest.back())});
            arr[testinexam.back()] = 1;
            /* cout << "move " << examintest.back() << ' ' << testinexam.back() << '\n'; */
            vec.pb({to_string(examintest.back()),to_string(testinexam.back())});
            freetest.back() = examintest.back();
            testinexam.pop_back();
            examintest.pop_back();
        }
    }
    /* whatis(freeexam) */
    /* whatis(freetest) */
    /* whatis(testinexam) */
    /* whatis(examintest) */
    /*     FORR(i,arr) */
    /*         cout << i; */
    /*     cout << '\n'; */
    /*     cout.flush(); */
    while(testinexam.size()){
        if(!freetest.empty()){
            arr[freetest.back()] = 2;
            /* cout << "move " << testinexam.back() << ' ' << freetest.back() << '\n'; */
            vec.pb({to_string(testinexam.back()),to_string(freetest.back())});
            arr[testinexam.back()] = 0;
            /* whatis(freeexam.size()) */
            freeexam.pb(testinexam.back());
            freetest.pop_back();
            testinexam.pop_back();
        }
        else{
            arr[testinexam.back()] = 0;
            arr[freeexam.back()] = 1;
            /* cout << "move " << examintest.back() << ' ' << freeexam.back() << '\n'; */
            vec.pb({to_string(examintest.back()),to_string(freeexam.back())});
            arr[examintest.back()] = 2;
            /* cout << "move " << testinexam.back() << ' ' << examintest.back() << '\n'; */
            vec.pb({to_string(testinexam.back()),to_string(examintest.back())});
            freeexam.back() = testinexam.back();
            testinexam.pop_back();
            examintest.pop_back();
        }
    }
    /* whatis(freeexam) */
    /* whatis(freetest) */
    /* whatis(testinexam) */
    /* whatis(examintest) */
    /*     FORR(i,arr) */
    /*         cout << i; */
    /*     cout << '\n'; */
    /*     cout.flush(); */
    FORR(i,exam){
        /* if(!freeexam.empty()){ */
            arr[freeexam.back()] = 1;
            /* cout << "move " << i << ' ' << freeexam.back() << '\n'; */
            vec.pb({i,to_string(freeexam.back())});
            freeexam.pop_back();
        /* } */
        /* else{ */
        /*     arr[freetest.back()] = 2; */
        /*     /1* cout << "move " << testinexam.back() << ' ' << freetest.back() << '\n'; *1/ */
        /*     vec.pb({to_string(testinexam.back()),to_string(freetest.back())}); */
        /*     arr[testinexam.back()] = 1; */
        /*     /1* cout << "move " << i << ' ' << testinexam.back() << '\n'; *1/ */
        /*     vec.pb({i,to_string(testinexam.back())}); */
        /*     testinexam.pop_back(); */
        /*     freetest.pop_back(); */
        /* } */
    }
    /* whatis(freeexam) */
    /* whatis(freetest) */
    /* whatis(testinexam) */
    /* whatis(examintest) */
    /*     FORR(i,arr) */
    /*         cout << i; */
    /*     cout << '\n'; */
    /*     cout.flush(); */
    FORR(i,test){
        /* FORR(i,arr) */
        /*     cout << i; */
        /* cout << '\n'; */
        /* cout.flush(); */
        /* if(!freetest.empty()){ */
            arr[freetest.back()] = 2;
            /* cout << "move " << i << ' ' << freetest.back() << '\n'; */
            vec.pb({i,to_string(freetest.back())});
            freetest.pop_back();
        /* } */
        /* else{ */
        /*     FORR(i,arr) */
        /*         cout << i; */
        /*     whatis(freeexam.size()) */
        /*     /1* whatis(freeexam.back()) *1/ */
        /*     arr[freeexam.back()] = 1; */
        /*     /1* cout << "move " << examintest.back() << ' ' << freeexam.back() << '\n'; *1/ */
        /*     vec.pb({to_string(examintest.back()),to_string(freeexam.back())}); */
        /*     arr[examintest.back()] = 2; */
        /*     /1* cout << "move " << i << ' ' << examintest.back() << '\n'; *1/ */
        /*     vec.pb({i,to_string(examintest.back())}); */
        /*     examintest.pop_back(); */
        /*     freeexam.pop_back(); */
        /* } */
    }
    cout << vec.size() << '\n';
    FORR(i,vec){
        cout << "move " << i.e1 << ' ' << i.e2 << '\n';
    }
    /* whatis(freetest.size()) */
    /* FORR(i,arr) */
    /*     cout << i; */
}