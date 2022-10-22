

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct Unit{
  int H,W;
  vector<string> G;

  Unit(vector<string> newG = {}) :
    H((int)newG.size()),
    W(0),
    G(move(newG))
  {
    for(auto& g : G) W = max(W,(int)g.size());
    for(auto& g : G) g.resize(W,' ');
  }
  virtual ~Unit() = default;

  static Unit liter(string S){
    int H=3, W=S.size()+4;
    vector<string> G(H);
    G[0] = "+" + string(W-2,'-') + "+";
    G[1] = "+ " + S + " +";
    G[2] = "+" + string(W-2,'-') + "+";
    return Unit(move(G));
  }
  static Unit merge_or(const vector<Unit>& V){
    int H=0, W=0;
    rep(vi,V.size()){
      const Unit& u=V[vi];
      if(vi!=0) H++; H+=u.H;
      W = max(W,u.W);
    }
    W+=6;
    vector<string> G(H);
    int y=0;
    rep(vi,V.size()){
      const Unit& u=V[vi];
      if(vi!=0) G[y++] = "|" + string(W-2,' ') + "|";
      rep(yy,u.H){
        if(yy>1 && vi==V.size()-1) G[y++] = "   " + u.G[yy] + string(W-6-u.W,' ') + "   ";
        else if(yy<1 && vi==0)     G[y++] = "   " + u.G[yy] + string(W-6-u.W,' ') + "   ";
        else if(yy==1)             G[y++] = "+->" + u.G[yy] + string(W-6-u.W,'-') + "->+";
        else                       G[y++] = "|  " + u.G[yy] + string(W-6-u.W,' ') + "  |";
      }
    }
    return Unit(move(G));
  }
  static Unit merge_and(const vector<Unit>& V){
    int H=0, W=0;
    rep(vi,V.size()){
      const Unit& u=V[vi];
      H = max(H,u.H);
      if(vi!=0) W+=2; W+=u.W;
    }
    vector<string> G(H);
    rep(vi,V.size()){
      const Unit& u=V[vi];
      if(vi!=0) rep(y,H){
        if(y==1) G[y] += "->";
        else     G[y] += "  ";
      }
      rep(y,H){
        if(y<u.H) G[y] += u.G[y];
        else      G[y] += string(u.W,' ');
      }
    }
    return Unit(move(G));
  }
  Unit& plus(){
    H+=2; W+=6;
    vector<string> newG(H);
    for(int y=0; y<H-2; y++){
      if(y<1)       newG[y] = "   " + G[y] + "   ";
      else if(y==1) newG[y] = "+->" + G[y] + "->+";
      else          newG[y] = "|  " + G[y] + "  |";
    }
    newG[H-2] = "|" + string(W-2,' ') + "|";
    newG[H-1] = "+<" + string(W-3,'-') + "+";
    G = move(newG);
    return *this;
  }
  Unit& question(){
    H+=3; W+=6;
    vector<string> newG(H);
    newG[0] = string(W,' ');
    newG[1] = "+" + string(W-3,'-') + ">+";
    newG[2] = "|" + string(W-2,' ') + "|";
    for(int y=0; y<H-3; y++){
      if(y<1)       newG[y+3] = "|  " + G[y] + "  |";
      else if(y==1) newG[y+3] = "+->" + G[y] + "->+";
      else          newG[y+3] = "   " + G[y] + "   ";
    }
    G = move(newG);
    return *this;
  }
  Unit& asterisk(){
    H+=5; W+=6;
    vector<string> newG(H);
    newG[0] = string(W,' ');
    newG[1] = "+" + string(W-3,'-') + ">+";
    newG[2] = "|" + string(W-2,' ') + "|";
    for(int y=0; y<H-5; y++){
      if(y<1)       newG[y+3] = "|  " + G[y] + "  |";
      else if(y==1) newG[y+3] = "+->" + G[y] + "->+";
      else          newG[y+3] = "|  " + G[y] + "  |";
    }
    newG[H-2] = "|" + string(W-2,' ') + "|";
    newG[H-1] = "+<" + string(W-3,'-') + "+";
    G = move(newG);
    return *this;
  }
  void print(){
    int resH = H, resW = W+6;
    vector<string> buf(H);
    for(int y=0; y<H; y++){
      if(y==1) buf[y] = "S->" + G[y] + "->F";
      else     buf[y] = "   " + G[y] + "   ";
    }
    printf("%d %d\n",resH,resW);
    rep(y,H) printf("%s\n",buf[y].c_str());
  }
  
private:
  static Unit from_expression_readliter(string::iterator& p, string::iterator endp){
    assert(p != endp);
    string S;
    bool done = false;
    while(!done){
      if(p == endp){ done = true; break; }
      switch(*p){
      case '|': case '(': case ')':
        done = true;
        break;
      case '+': case '*': case '?':
        if(S.size() > 1){
          S.pop_back();
          p--;
        }
        done = true;
        break;
      default:
        S.push_back(*p);
        p++;
      }
    }
    return Unit::liter(S);
  }
  static Unit from_expression_readatom(string::iterator& p, string::iterator endp){
    assert(p != endp);
    Unit res;
    switch(*p){
    case '(':
      res = from_expression_readexpr(++p,endp);
      assert(p != endp);
      assert(*p == ')');
      p++;
    break;
    case ')': case '|': case '+': case '*': case '?':
      assert(false);
    default:
      res = from_expression_readliter(p,endp);
    }
    bool done = false;
    while(!done){
      if(p == endp){ done=true; break; }
      switch(*p){
      case '+': res.plus(); p++; break;
      case '*': res.asterisk(); p++; break;
      case '?': res.question(); p++; break;
      default: done=true;
      }
    }
    return move(res);
  }
  static Unit from_expression_readterm(string::iterator& p, string::iterator endp){
    assert(p != endp);
    vector<Unit> buf;
    bool done = false;
    while(!done){
      buf.push_back(from_expression_readatom(p,endp));
      if(p==endp){ done=true; continue; }
      switch(*p){
      case ')': case '|': case '+': case '*': case '?':
        done = true;
        break;
      }
      continue;
    }
    if(buf.size()==1) return move(buf[0]);
    return Unit::merge_and(buf);
  }
  static Unit from_expression_readexpr(string::iterator& p, string::iterator endp){
    assert(p != endp);
    vector<Unit> buf;
    bool done = false;
    while(!done){
      buf.push_back(from_expression_readterm(p,endp));
      if(p==endp){ done=true; continue; }
      switch(*p){
      case '|':
        p++;
        break;
      default:
        done = true;
        break;
      }
      continue;
    }
    if(buf.size()==1) return move(buf[0]);
    return Unit::merge_or(buf);
  }
public:

  static Unit from_expression_recursive(string::iterator expr_begin, string::iterator expr_end){
    auto x = from_expression_readexpr(expr_begin,expr_end);
    while(expr_begin != expr_end){
      cout<<*expr_begin;
      expr_begin++;
    }
    return move(x);
  }
};

void printSample(){
  //NE?(ER)C++|(IS)*?|(CHA((LL))ENGING)
  Unit::merge_or({
    Unit::merge_and({
      Unit::liter("N"),
      Unit::liter("E").question(),
      Unit::liter("ER"),
      Unit::liter("C").plus().plus()
    }),
    Unit::liter("IS").asterisk().question(),
    Unit::merge_and({
      Unit::liter("CHA"),
      Unit::liter("LL"),
      Unit::liter("ENGING")
    })
  }).print();
}

int main(){
  string expr; cin>>expr;
  Unit::from_expression_recursive(expr.begin(),expr.end()).print();
  return 0;
}