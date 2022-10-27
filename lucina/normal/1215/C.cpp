#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n,ct[30];
bool change[maxn];
char buf[maxn];
string s,t;
map<pair<int,int>,vector<int>> ss;
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 21
#endif // LOCAL
void reads(string &x){
    scanf("%s",buf);
    x= string(buf);
}
struct pa{
    int f,s,idx;
};

int main(){
    scanf("%d",&n);
    reads(s);reads(t);
    for(auto i:s){
        ct[i-'a']++;
    }
    for(auto i:t)
        ct[i-'a']++;
    for(int i=0;i <=25;i++){
    if(ct[i] % 2)return cout<<-1,0;
    }
    n = s.length();
    for(int i=0 ;i<n;i++){
        if(s[i] == t[i])continue;
        ss[make_pair(s[i]-'a',t[i]-'a')].push_back(i+1);
    }
    vector<pa> v;
    vector<pair<int,int>> ans;
    for(auto &j:ss){
        while((int)j.second.size() >= 2){
            int x1 = (j.second.back());
            j.second.pop_back();
            int x2 = (j.second.back());
            j.second.pop_back();
            ans.push_back({x2,x1});
        }
        if(j.second.empty()){
            ;
        }
        else{
            v.push_back({j.first.first,j.first.second,j.second.back()});
        }
    }
    while(!v.empty()){
        bool ss = true;
        for(auto it = v.begin()+1;it!=v.end(); it++){
            if(v[0].f == it->f){
                ans.push_back(make_pair(v[0].idx,it->idx));
                pa wait = {it->s,v[0].s,it->idx};
                v.erase(it);
                v.erase(v.begin());
                v.push_back(wait);
                ss = false;
                break;
            }
        }
        if(ss){
            ans.push_back(make_pair(v[0].idx,v[0].idx));
            swap(v[0].f,v[0].s);
            vector<pa> :: iterator todel = v.end();
            pa topush;
            for(auto it = v.begin()+1;it!=v.end(); it++){
            if(v[0].f == it->f){
                ans.push_back(make_pair(v[0].idx,it->idx));
                topush = {it->s,v[0].s,it->idx};
                todel = it;
                //assert(it != v.begin());
                ss = false;
                break;
            }
            }
            v.erase(todel);
            v.erase(v.begin());
            v.push_back(topush);
        }
        bool found = true;
        while(found){
        found = false;
        for(auto it = v.begin();it!=v.end();++it){
            if(it->f == it->s){
                v.erase(it);
                found  = true;
                break;
            }
        }
        }
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
            printf("%d %d\n",ans[i].first,ans[i].second);
    }
}
/*
    Good Luck
        -Lucina
*/