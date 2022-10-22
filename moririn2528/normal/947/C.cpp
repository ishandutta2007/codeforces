#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%d%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%lld%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}

typedef struct trie_node{
    int to[2];
    int size=0;
}trie_node;
vector<trie_node> trie_tree;

void trie_init(){
    trie_node trie_tn;
    memset(trie_tn.to,-1,sizeof(trie_tn.to));
    trie_tree.push_back(trie_tn);
}

void trie_set(int trie_a,int trie_n=29,int pos=0){
    trie_tree[pos].size++;
    if(trie_n==-1)return;
    int trie_t=(trie_a&(1<<trie_n))?1:0;
    int trie_p=trie_tree[pos].to[trie_t];
    if(trie_p!=-1){
        trie_set(trie_a,trie_n-1,trie_p);
        return;
    }
    trie_node trie_tn;
    memset(trie_tn.to,-1,sizeof(trie_tn.to));
    trie_tree[pos].to[trie_t]=trie_tree.size(),trie_p=trie_tree.size();
    trie_tree.push_back(trie_tn);
    trie_set(trie_a,trie_n-1,trie_p);
}

int trie_find(int trie_a,int trie_n=29,int trie_s=0,int trie_pos=0){
    if(trie_n==-1){
        trie_tree[trie_pos].size--;
        return trie_s;
    }
    int trie_t=(trie_a&(1<<trie_n))?1:0;
    int trie_p=trie_tree[trie_pos].to[trie_t];
    if(trie_p==-1 || trie_tree[trie_p].size==0)trie_t=1-trie_t;
    trie_p=trie_tree[trie_pos].to[trie_t];
    trie_s<<=1,trie_s+=trie_t;
    trie_tree[trie_pos].size--;
    return trie_find(trie_a,trie_n-1,trie_s,trie_p);
}
int t[300005];

int main(){
    LL n,m;
    LL i,j,k;
    LL a,b,c;
    trie_init();
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t[i];
    }
    for(i=0;i<n;i++){
        cin>>a;
        trie_set(a);
    }
    for(i=0;i<n;i++){
        a=trie_find(t[i]);
        //cout<<a<<endl;
        t[i]^=a;
    }
    array_show(t,n);
}