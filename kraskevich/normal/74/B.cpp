#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int n, m, k;
int curK, curZ, dir;
int fail = -1;
//direction 1 - to tail -1 - to head

bool solve(bool stop)
{
     if(!stop)
     {
              if(fabs(curK - curZ) != 1)
              {
                           curK += dir;
                           if(curK == n && dir == 1)
                                   dir = -1;
                           if(curK == 1 && dir == -1)
                                   dir = 1;
                           return true;
              }
              else
                  curZ += dir, curK += dir;
              if(curK == n && dir == 1)
                      dir = -1;
              if(curK == 1 && dir == -1)
                      dir = 1;
              if(curZ > n || curZ == 0)
                      return false;
              else
                  return true;
     }
     else
     {
         curK += dir;
         if(curK == 1)      
                curZ = n;
         if(curK == n)
                 curZ = 1;
         if(curK != 1 && curK != n)
         {
                 if(dir == 1)
                        curZ = 1;
                 else
                     curZ = n;
         }
         if(curK == n && dir == 1)
                 dir = -1;
         if(curK == 1 && dir == -1)
                 dir = 1;
         return true;
     }
}

int main()
{
     ios_base::sync_with_stdio(0);
    
     cin >> n >> m >> k;
     scanf("\n");
    
     string s;
     cin >> s;
     cin >> s;
    
     if(s == "head")
         dir = -1;
     else
         dir = 1;
     curZ = m;
     curK = k;
     if(curK == n && dir == 1)
             dir = -1;
     if(curK == 1 && dir == -1)
             dir = 1;
         
     string type;
     cin >> type;
     
     for(int i = 0; i < type.length(); ++i)
     {
             bool cur = solve(type[i] == '1' ? true : false);
             if(!cur)
             {
                     fail = i + 1;
                     break;
             }
     }
     
     if(fail == -1)
             cout << "Stowaway";
     else
         cout << "Controller " << fail;
     
     cin >> n;
     
     return 0;
}