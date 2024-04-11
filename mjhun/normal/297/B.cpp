#include <cstdio>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

vector<int> v;
map<int,int> mp;

int main(){
    int n,m,i,j,k,s;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;++i){
        scanf("%d",&k);
        mp[k]++;
    }
    for(j=0;j<m;++j){
        scanf("%d",&k);
        mp[k]--;
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
        v.push_back(it->second);
    }
    s=0;
    for(i=v.size()-1;s<1&&i>=0;--i){
        s+=v[i];
    }
    puts(s>0?"YES":"NO");
    return 0;
}