#include <iostream>
#include <string>
using namespace std;

string s;

bool Good(char c)
{
     return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' ||
            '0' <= c && c <= '9' || c == '_';
} 

bool CorU(int l, int r)
{
     int len = r - l + 1;
     if (len < 1 || len > 16) return false;
     for (int i = l; i <= r; i++)
         if (!Good(s[i])) return false;
     return true;
}

bool CorH(int l, int r)
{
     int len = r - l + 1;
     if (len < 1 || len > 32) return false;
     len = 0;
     for (int i = l; i <= r; i++)
         if (s[i] == '.') {
                  if (len < 1 || len > 16) return false;
                  len = 0;
         } else {
                if (!Good(s[i])) return false;
                len++;
         }
     return 1 <= len && len <= 16;
}

bool CorrectID()
{
     int eta = s.find('@');
     int slash = s.find_last_of('/');
     if (eta == string::npos) return false;
     if (slash == string::npos) 
        return CorU(0, eta - 1) && CorH(eta + 1, s.length() - 1);
     return CorU(0, eta - 1) && CorH(eta + 1, slash - 1) && CorU(slash + 1, s.length() - 1); 
}

int main()
{
    getline(cin, s);
    if (CorrectID()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}