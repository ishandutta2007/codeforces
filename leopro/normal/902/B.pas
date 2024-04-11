uses classes;

type
  TVertex = class
    Parent: TVertex;
    ChildNumber: SmallInt;
    children: TList;
    NowColor, ExpectedColor: SmallInt;

    function Child(number: SmallInt): TVertex;
    Constructor Create;
  end;

  constructor TVertex.Create;
  begin
    NowColor := 0;
    children := TList.Create;
  end;

  function TVertex.Child(number: SmallInt): TVertex;
  begin
    Result := TVertex(children[number]);
  end;

var
  vertices: array [1..10000] of TVertex;
  N, i, Ans, x: SmallInt;

function Dfs(vertex: TVertex): SmallInt;
var
  p: Pointer;
begin
  Result := 0;
  if (vertex.ExpectedColor <> vertex.NowColor) then Result := 1;
  for p in vertex.children do
  begin
    TVertex(p).NowColor := vertex.ExpectedColor;
    Result += dfs(TVertex(p));
  end;
end;

begin
  ReadLn(N);
  For i := 1 to N do vertices[i] := TVertex.Create;
  For i := 2 to N do
  begin
    Read(x);
    vertices[x].children.Add(vertices[i]);
    vertices[i].Parent := vertices[x];
    vertices[i].ChildNumber := vertices[x].children.Count - 1;
  end;
  ReadLn;
  For i := 1 to N do
  begin
    Read(vertices[i].ExpectedColor);
    vertices[i].NowColor := -1;
  end;
  ReadLn;

  Ans := Dfs(vertices[1]);
  WriteLn(Ans);
end.