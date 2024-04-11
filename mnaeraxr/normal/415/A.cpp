#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

int events[86405];

bool t[101];

int main()
{
    int lights,ev;
    cin >> lights >> ev;
    int max = 101;
    int cur;
    for (int i = 0; i < ev; i++)
    {
        cin >> cur;
        if (cur < max)
        {
            t[cur] = true;
            max = cur;
        }
    }
    int tt = 1;
    for (int i = 1; i < lights; i++)
    {
        if (t[i])
            tt = i;
        cout << tt << " ";
    }
    if (t[lights])
        tt = lights;
    cout << tt << "\n";
    
//  int total;
//  cin >> total;
//  for (int i = 1; i < total + 1; i++)
//  {
//      int ev;
//      cin >> ev;
//      int a,b;
//      bool conflict = false;
//      for (int j = 0; j < ev; j++)
//      {
//          cin >> a >> b;
//          if (conflict)
//              continue;
//          for (int k = a; k <= b; k++)
//          {
//              if (events[k] == i)
//                  conflict = true;
//              else
//                  events[k] = i;
//          }
//      }
//      if (conflict)
//          cout << "Conflict\n";
//      else
//          cout << "No Conflict\n";
//  }
}