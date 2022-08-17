#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1001];
bool visited[10000];

void DFS(int a)
{
    visited[a] = true;
    for(int i = 0; i < v[a].size() ;i++)
    {
        if (!visited[v[a][i]]) DFS(v[a][i]);
    }
}

int main()
{

  int c,r;
  char a[105];
  cin >> c >> r;
  for (int i = 0; i < c ; i++)
    for (int j = 0; j < r; j++){
        char x;

        if (i == c-1) cin >> a[j];
        else cin >> x;
    }

    bool b = 0; int count = 0;
    for (int i  = 0 ; i < r; i++){
        if (!b && a[i] != '.') {count++; b = 1; continue;}
        if (a[i] == '.') b = 0;
    }
    cout << count;
    return 0;
}