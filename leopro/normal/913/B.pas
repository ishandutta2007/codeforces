uses classes;

type
  TVertex = class
    children: TList;

    function MoreTwoLeaves: Boolean;
    function Child(number: SmallInt): TVertex;
    Constructor Create;
  end;

  constructor TVertex.Create;
  begin
    children := TList.Create;
  end;

  function TVertex.Child(number: SmallInt): TVertex;
  begin
    Result := TVertex(children[number]);
  end;

  function TVertex.MoreTwoLeaves: Boolean;
  var
    i, counter: LongInt;
  begin
    counter := 0;
    For i := 0 to children.Count-1 do If Child(i).children.Count = 0 then inc(counter);
    If counter > 2 then Result := True else Result := False;
  end;

var
  verticies: array [1..10000] of TVertex;
  N, parent, i: SmallInt;
  spruce: Boolean;

procedure Yes(Cond: Boolean);
begin
  If Cond then WriteLn('Yes') else WriteLn('No');
end;


begin
  Read(N);
  For i := 1 to N do verticies[i] := TVertex.create;
  For i := 2 to N do
  begin
    ReadLn(parent);
    verticies[parent].children.add(Pointer(verticies[i]));
  end;
  spruce:=True;
  For i := 1 to N do begin If not((verticies[i].MoreTwoLeaves) or (verticies[i].children.Count = 0)) then spruce:=false;end;
  Yes(spruce);
end.