uses
  Classes, sysutils;

type
  TVertex = class
    children: TList;
  end;

var
  Tree: array [1..100000] of TVertex;
  i, n, v1, v2, amount: Int32;
  ManyChildren1, ManyChildren2: Int32;
  OneChildren: array [1..100000] of Int32;

begin
  ReadLn(n);
  For i := 1 to n do
  begin
    Tree[i] := TVertex.Create;
    Tree[i].children := TList.Create;
    Tree[i].children.Clear;
  end;
  For i := 2 to n do
  begin
    ReadLn(v1, v2);
    Tree[v1].children.Add(Tree[v2]);
    Tree[v2].children.Add(Tree[v1]);
  end;

  ManyChildren1 := 0;
  ManyChildren2 := 0;
  For i := 1 to n do
  begin
    If Tree[i].children.Count > 2 then
    begin
      If ManyChildren1 = 0 then ManyChildren1 := i else ManyChildren2 := i;
    end;
  end;

  If (ManyChildren1 <> 0) and (ManyChildren2 <> 0) then
  begin
    WriteLn('No');
    Exit;
  end;
  
  WriteLn('Yes');
  
  amount := 0;
  For i := 1 to n do
  begin
    If Tree[i].children.Count = 1 then
    begin
      inc(amount);
      OneChildren[amount] := i;
    end;
  end;

  If ManyChildren1 > 0 then
  begin
    WriteLn((amount+1) div 2);
    For i := 1 to amount div 2 do
    begin
      WriteLn(OneChildren[i*2-1], ' ', OneChildren[i*2]);
    end;
    If amount mod 2 = 1 then  WriteLn(ManyChildren1, ' ', OneChildren[amount]);
    Exit;
  end;
  WriteLn('1');
  WriteLn(OneChildren[1], ' ', OneChildren[2]);
end.