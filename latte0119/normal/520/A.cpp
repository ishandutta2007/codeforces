#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cctype>
#include<cstdlib>
using namespace std;
int main(){
    char str[128];
    int n;
    bool f[32];
    fill(f,f+32,false);
    scanf("%d%s",&n,str);
    for(int i=0;str[i];i++){
        str[i]=tolower(str[i]);
        f[str[i]-'a']=true;
    }
    bool flag=true;
    for(int i=0;i+'a'<='z';i++){
        flag&=f[i];
    }
    puts(flag?"YES":"NO");
    return 0;
}