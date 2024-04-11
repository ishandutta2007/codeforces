uses
Classes, math;

type
  TVertex = class
    children: TList;
    parent: TVertex;
    a, s: Int64;
  end;

var
  n, i, p_: Int32;
  sum: Int64;
  Tree: array [0..100000] of TVertex;
procedure dfs(v: TVertex);
var
  minval: Int64 = 2000000000;
  p: Pointer;
begin
  If v.s = -1 then
  begin
    if v.children.count > 0 then
    begin
      for p in v.children do
        minval:=min(minval, TVertex(p).s);
      v.s := minval;
      v.a := (v.s - v.parent.s);
    end else
    begin
      v.a := 0;
      v.s := v.parent.s;
    end;
  end else
  begin
    v.a := (v.s - v.parent.s);
  end;    
  for p in v.children do
    dfs(TVertex(p));
end;

function sum_(v: TVertex): Int64;
var
  p: Pointer;
begin
  Result := v.a;
  If v.a < 0 then  Result := -1000000000000000;
  for p in v.children do
    Result += sum_(TVertex(p));
end;


begin
  readLn(n);
  for i := 0 to n do
  begin
    Tree[i] := TVertex.Create;
    Tree[i].children:=TList.Create;
  end;
  Tree[1].parent := Tree[0];
  Tree[0].a := 0;
  Tree[0].s := 0;
  For i := 2 to n do
  begin
    Read(p_);
    Tree[p_].children.Add(Tree[i]);
    Tree[i].parent := Tree[p_];
  end; ReadLn;
  For i := 1 to n do
  begin
    Read(Tree[i].s);
  end;  ReadLn;
  dfs(Tree[1]);
  sum := sum_(Tree[1]);
  If sum < 0 then WriteLn('-1') else WriteLn(sum);
  ReadLn;

end.