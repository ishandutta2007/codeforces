#include <iostream>

#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int main()
{ char s[101];  int k=0,l;
  bool e;  cin>>s;

 l=strlen(s);
 if (islower(s[0])) e=true; else e=false;
 for (int i=0;i<l;i++) if (!islower(s[i])) k++;
 if (k==l)  for (int i=0;i<l;i++) s[i]=(char)(s[i]+32); else
  if  (k==l-1 && e) { s[0]=s[0]-32; for (int i=1;i<l;i++)  s[i]=(char) (s[i]+32);}
  for (int i=0;i<l;i++) cout<<s[i];

}