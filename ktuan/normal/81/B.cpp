#include <cstdio>
#include <cstring>
using namespace std;
int n,first,last;
char c,s[255],t[255];
int main(){
    while (scanf("%c",&c)!=EOF && c != 10 && c != 13) s[n++]=c;
    for (int i=0; i<n; i++){
        if (s[i]==' '){
           if (t[last-1]==' ' || t[last-1]=='.') continue;
           else t[last++]=' ';
        }
        else if (s[i]==','){
             if (t[last-1]!=' ' || (t[last-1]==' ' && t[last-2]==',')){
                t[last++]=',';
                t[last++]=' ';
             }
             else{
                  t[last-1]=',';
                  t[last++]=' ';
             }
        }
        else if (s[i]=='.'){
             if (t[last-1]==' '){
                for (int k=0; k<3; k++) t[last++]='.';
             }
             else{
                  t[last++]=' ';
                  for (int k=0; k<3; k++) t[last++]='.';
             }
             i+=2;
        }
        else t[last++]=s[i];
    }
    while (t[last-1]==' ') last--;
    if (t[first]==' ') first++;
    for (int i=first; i<last; i++) printf("%c",t[i]);
    return 0;
}