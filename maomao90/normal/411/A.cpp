#include<bits/stdc++.h>
using namespace std;

int main()
{   
   string s;
   int cnts=0,cntd=0,cntp=0;
   cin>>s;
   for(int i=0;s[i]!='\0';i++)
   {
        if(s[i]>='a')
        cnts++;
        else if(s[i]>='A'&&s[i]<='Z')
        cntp++;
        else if(s[i]>='0'&&s[i]<='9')
        cntd++;
       
   }
   if(cnts&&cntp&&cntd&&s.length()>=5)
   cout<<"Correct";
   else
   cout<<"Too weak";
  
}