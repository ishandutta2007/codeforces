#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
   int flag=0;
   char s[100005];
   scanf("%s", s);
   for(int i=0; i<strlen(s); i++) {
       if(s[i]!='A' && s[i]!='H' && s[i]!='I' && s[i]!='M' && s[i]!='O' && s[i]!='T' && s[i]!='U' && s[i]!='V' && s[i]!='W' && s[i]!='X' && s[i]!='Y') {
           flag=1;
           break;
       }
   }
   if(flag==0) {
       for(int i=0; i<strlen(s)/2+1; i++) {
           if(s[i]!=s[strlen(s)-i-1]) {
               flag=1;
               break;
           }
       }
   }
   if(flag==1) printf("NO");
   else printf("YES");
   return 0;
}