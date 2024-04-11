#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
 string x;
 cin>>x;
 int S,i,t;
 S=0;
 int alf[1000];
 alf[0]=97;
    for (i=0;i<x.size();i++){
    alf[i+1]=(int) x[i];
 }
   for (i=0;i<x.size();i++){
        t=abs(alf[i+1]-alf[i]);
   if (t<13) {
    S+=t;
   }
   else {
    S+=26-t;
   }

   }
   cout<<S;


    return 0;
}