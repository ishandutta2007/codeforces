uses
  Classes, sysutils;

type
  TVertex = class
    children: TList;
    number: Int32;
    component: Int32;
  end;

var
  Tree: array [1..200000] of TVertex;
  Components: array [1..200000] of Int32;  //Keys are numbers of components and values are numbers of vertices

function Check(u, from, start: Int32): Boolean;
begin
  If (Tree[u] = Tree[start]) then Result := (Tree[u].children.Count = 2) else
  begin
    If Tree[u].children.Count <> 2 then Result := False else
    begin
      If TVertex(Tree[u].children[0]).number = from then
      begin
        Result := Check(TVertex(Tree[u].children[1]).number, u, start);
      end else
      begin
        Result := Check(TVertex(Tree[u].children[0]).number, u, start);
      end;
    end;
  end;
end;

procedure dfs(v: Int32; c: Int32);
var
  p: Pointer;
begin
  Tree[v].component := c;
  Components[c] := v;
  For p in Tree[v].children do
  begin
    If TVertex(p).component = 0 then
    begin
      TVertex(p).component := c;
      dfs(TVertex(p).number, c)
    end;
  end;
end;

var
  n, m, i, u, v, ans, c: Int32;

begin
  ReadLn(n, m);
  For i := 1 to n do
  begin
    Tree[i] := TVertex.Create;
    Tree[i].children := TList.Create;
    Tree[i].children.Clear;
    Tree[i].number := i;
    Tree[i].component := 0;
  end;
  For i := 1 to m do
  begin
    ReadLn(u, v);
    Tree[u].children.Add(Tree[v]);
    Tree[v].children.Add(Tree[u]);
  end;
  ans := 0;

  c := 0;
  For i := 1 to n do
  begin
    If Tree[i].component = 0 then
    begin
      inc(c);
      dfs(i, c);
    end;
  end;

  For i := 1 to c do
  begin
    If Tree[Components[i]].children.Count > 0 then
    If Check(Components[i], TVertex(Tree[Components[i]].children[0]).number, TVertex(Tree[Components[i]].children[0]).number) then inc(ans);
  end;
  WriteLn(ans);
  ReadLn;
end.