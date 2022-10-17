#include <cstdio>
#include <map>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int n;
char s[100];
map<string, string> m;

int main() {
  m["purple"] = "Power";
  m["green"] = "Time";
  m["blue"] = "Space";
  m["orange"] = "Soul";
  m["red"] = "Reality";
  m["yellow"] = "Mind";
  scanf("%d",&n);
  REP(i,n) {
    scanf("%s",s);
    m.erase(s);
  }
  printf("%d\n",(int)m.size());
  FORE(i,m) printf("%s\n",i->second.c_str());
}