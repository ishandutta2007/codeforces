type
  arrays = array [1..200000] of Int32;

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
        If tmp[from2] > tmp[from1] then a[p] := tmp[inc(from1)] else a[p] := tmp[inc(from2)];
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
  n, k, i: Int32;
  a, tmp: arrays;

begin
  ReadLn(n, k);
  For i := 1 to n do
  begin
    Read(a[i]);
    tmp[i] := a[i];
  end;
  ReadLn;
  Sort(a, tmp, 1, n);
  If k = n then
  begin
    WriteLn('1000000000');
    Readln;
  end else
  begin
    If (k = 0) then
    begin
      If a[1] = 1 then WriteLn('-1') else WriteLn('1');
      Exit;
    end;
    If a[k] = a[k+1] then
    begin
      WriteLn('-1');  Readln;
    end else
    begin
      WriteLn(a[k]);
      Readln;
    end;
  end;
end.