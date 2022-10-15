uses
Classes;
type
  TVertex = class
    Parent: TVertex;
    children: TList;
    LeafChildren: Int32;
    Leaf: Boolean;
    constructor Create;
  end;
  arrays = array [1..100000] of TVertex;

constructor TVertex.Create;
begin
  children := TList.Create;
  children.Clear;
  Leaf := False;
  Parent := nil;
end;

function inc(var a: Int32): Int32; begin inc := a; a := a + 1; end;

function Less(a, b: TVertex): Boolean;
begin
  If a.LeafChildren < b.LeafChildren then Result := True else Result := False;  //ascending
end;

procedure Merge(var a, tmp: arrays; from1, till2: Int32);
var
  till1, from2, p: Int32;
begin
  till1 := (from1 + till2) div 2;
  from2 := till1 + 1;
  For p := from1 to till2 do tmp[p] := a[p];
  For p := from1 to till2 do
  begin
    If from1 > till1 then a[p] := tmp[inc(from2)] else
    begin
      If from2 > till2 then a[p] := tmp[inc(from1)] else
      begin
        If Less(tmp[from2], (tmp[from1])) then a[p] := tmp[inc(from2)] else a[p] := tmp[inc(from1)];
      end;
    end;
  end;
end;

procedure Sort(var a, tmp: arrays; from, till: Int32);
var
  middle: Int32;
begin
  middle := (from + till) div 2;
  If from < middle then Sort(a, tmp, from, middle);
  If middle+1 < till then Sort(a, tmp, middle+1, till);
  Merge(a, tmp, from, till);
end;

var
  n, i, j, x, ans: Int32;
  Tree, b: arrays;

function setint(v: TVertex): Int32;
var
  p: Pointer;
begin
  v.LeafChildren := 0;
  If v.Leaf then v.LeafChildren := 1 else
    For p in v.children do v.LeafChildren += setint(TVertex(p));
  Result := v.LeafChildren;
end;

var
  max: Int32;

begin
  ReadLn(n);
  For i := 1 to n do Tree[i] := TVertex.Create;
  For i := 2 to n do
  begin
    Read(x);
    Tree[i].Parent := Tree[x];
    Tree[x].children.Add(Tree[i]);
  end;
  If n > 1 then ReadLn;
  For i := 1 to n do
  begin
    If Tree[i].children.Count = 0 then Tree[i].Leaf := True;
  end;
  setint(tree[1]);
  Sort(Tree, b, 1, n);
  ans := 1;
  For i := 1 to n do
  begin
    If ans < Tree[i].LeafChildren then ans := Tree[i].LeafChildren;
    Write(ans, ' ');
  end;

  ReadLn;
end.