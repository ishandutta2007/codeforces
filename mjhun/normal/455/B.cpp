#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

struct trie {
    bool f;
    map<char,int> next;
};

trie t[100005];
int nt;

void tinit(){
    nt=1;
    t[0].f=false;
    t[0].next.clear();
}

void tinsert(char *S){
    int m=strlen(S);
    int p=0;
    for(int i=0;i<m;++i){
        if(t[p].next.find(S[i])==t[p].next.end()){
            t[nt].f=false;
            t[nt].next.clear();
            t[p].next[S[i]]=nt++;
        }
        p=t[p].next[S[i]];
    }
    t[p].f=true;
}

int winner(int p){
    for(map<char,int>::iterator it=t[p].next.begin();
            it!=t[p].next.end();++it){
        if(winner(it->second)==1){
            return 0;
        }
    }
    return 1;
}

int loser(int p){
    if(t[p].next.empty())return 0;
    for(map<char,int>::iterator it=t[p].next.begin();
            it!=t[p].next.end();++it){
        if(loser(it->second)==1){
            return 0;
        }
    }
    return 1;
}

int n,k;

char S[100005];

int qwe(int w, int l){
    if(w==0){
        if(l==0)return 0;
        else return 1-(k%2);
    }
    else return 1;
}

int main(){
    scanf("%d %d",&n,&k);
    tinit();gets(S);
    while(n--){
        gets(S);
        tinsert(S);
    }
    int w=winner(0), l=loser(0);
    puts(qwe(w,l)?"Second":"First");
    return 0;
}