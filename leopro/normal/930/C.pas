uses
  AVL_Tree, Math;

type
  TPoint = Class
    Cnt: Int32;
    LeftLen, RightLen: Int32;
    constructor Create(c: Int32);
  end;

constructor TPoint.Create(c: Int32);
begin
  Cnt := c;
  LeftLen := 0;
  RightLen := 0;
end;

function Compare(a, b: Pointer): Int32;
begin
  Result := TPoint(a).Cnt - TPoint(b).Cnt;
end;

function FindLess(tree: TAVLTree; Data: TPoint): TAVLTreeNode;
var
  Res: TAVLTreeNode;
begin
  Res := tree.FindNearest(Data);
  If Res <> nil then
  begin
    If TPoint(Res.Data).Cnt > Data.Cnt then Result := tree.FindPrecessor(Res) else Result := Res;
  end else
  begin
    Result := nil
  end;
end;

var
  n, m, i, l, r, additive, ans: Int32;
  Points: array [1..100000] of TPoint;
  Add, Left, Right: array [1..100001] of Int32;
  Tree: TAVLTree;
  MinNode, SameNode: TAVLTreeNode;

begin
  ReadLn(n, m);
  For i := 1 to m do Add[i] := 0;
  For i := 1 to n do
  begin
    ReadLn(l, r);
    inc(Add[l], 1);
    dec(Add[r+1], 1);
  end;
  additive := Add[1];
  for i := 1 to m do
  begin
    Points[i] := TPoint.Create(additive);
    inc(additive, Add[i+1]);
  end;

  Tree := TAVLTree.Create(@Compare);
  For i := 1 to m do Left[i] := 1000000000;

  For i := 1 to m do
  begin
    MinNode := FindLess(Tree, Points[i]);
    If MinNode = nil then Points[i].LeftLen := 1 else Points[i].LeftLen := TPoint(MinNode.Data).LeftLen + 1;
    If Left[Points[i].LeftLen] <= Points[i].Cnt then Continue;
    If Left[Points[i].LeftLen] < 1000000000 then
    begin
      Tree.Delete(Tree.Find(TPoint.Create(Left[Points[i].LeftLen])));
    end;
    Left[Points[i].LeftLen] := Points[i].Cnt;

    SameNode := Tree.Find(Points[i]);
    If SameNode <> nil then
    begin
      Left[TPoint(SameNode.Data).LeftLen] := 1000000000;
      Tree.Delete(SameNode);
    end;

    Tree.Add(Points[i]);
  end;
  Tree.Clear;

  For i := 1 to m do Right[i] := 1000000000;
  For i := m downto 1 do
  begin
    MinNode := FindLess(Tree, Points[i]);
    If MinNode = nil then Points[i].RightLen := 1 else Points[i].RightLen := TPoint(MinNode.Data).RightLen + 1;
    If Right[Points[i].RightLen] <= Points[i].Cnt then Continue;
    If Right[Points[i].RightLen] < 1000000000 then
    begin
      Tree.Delete(Tree.Find(TPoint.Create(Right[Points[i].RightLen])));
    end;
    Right[Points[i].RightLen] := Points[i].Cnt;

    SameNode := Tree.Find(Points[i]);
    If SameNode <> nil then
    begin
      Right[TPoint(SameNode.Data).RightLen] := 1000000000;
      Tree.Delete(SameNode);
    end;

    Tree.Add(Points[i]);
  end;

  ans := 0;
  For i := 1 to m do
  begin
    ans := max(ans, Points[i].LeftLen + Points[i].RightLen - 1);
  end;
  WriteLn(ans);
  ReadLn;
end.