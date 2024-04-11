#include <cstdio>
#include <cstring>
using namespace std;
char st[200],Cnum;
int len,Clen,i;
int main() {
    scanf("%s",&st);
    len=strlen(st);
    Clen=1;Cnum=st[0];
    for (i=1;i<len;i++) {
        if (st[i]==Cnum) Clen++; else Clen=1;Cnum=st[i];
        if (Clen>=7) break; 
    }
    if (Clen>=7) printf("YES"); else printf("NO");
}