type
  arrays = array [1..1000] of Int32; 

function inc1(var a: Int32): Int32; begin inc1 := a; inc(a); end;

procedure Merge(var a, tmp: arrays; from1, till2: Int32);
var
  till1, from2, p: Int32;
begin
  till1 := (from1 + till2) div 2;
  from2 := till1 + 1;
  For p := from1 to till2 do tmp[p] := a[p];
  For p := from1 to till2 do
  begin
    If from1 > till1 then a[p] := tmp[inc1(from2)] else
    begin
      If from2 > till2 then a[p] := tmp[inc1(from1)] else
      begin
        If tmp[from2] < tmp[from1] then a[p] := tmp[inc1(from2)] else a[p] := tmp[inc1(from1)];
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
  N, i: Int32;
  a, b: arrays;

begin
  ReadLn(N);
  For i := 1 to N do Read(a[i]);
  Sort(a, b, 1, n);
  WriteLn(a[(N+1) div 2]);
end.