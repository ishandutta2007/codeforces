type
  arrays = array [1..100] of Int64;

function More(int1, int2: Int64): Boolean;
begin
  While (int1 mod 3 = 0) and (int2 mod 3 = 0) do
  begin
    int1 := int1 div 3;
    int2 := int2 div 3;
  end;
  If int1 mod 3 = 0 then Result := False else
  begin
    If int2 mod 3 = 0 then Result := True else
    begin
      If int1 > int2 then Result := True else Result := False;
    end;
  end;
end;

function inc(var a: Int32): Int32; begin inc := a; a := a + 1; end;

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
        If More(tmp[from2], tmp[from1]) then a[p] := tmp[inc(from1)] else a[p] := tmp[inc(from2)];
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
  n, i: Int32;
  a, tmp: arrays;

begin
  ReadLn(n);
  For i := 1 to n do
  begin
    Read(a[i]);
    tmp[i] := a[i];
  end;
  ReadLn;
  Sort(a, tmp, 1, n);
  For i := 1 to n do
  begin
    Write(a[i], ' ');
  end;
  WriteLn();
  ReadLn;
end.