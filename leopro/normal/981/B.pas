uses
Math;

type
  TElement = Record
    number: Int32;
    money: Int32;
  end;

  ElementArray = array [1..100000] of TElement;

function inc1(var a: Int32): Int32; begin inc1 := a; a := a + 1; end;

function Less(a, b: TElement): Boolean;
begin
  If a.number < b.number then Result := True else Result := False;  //ascending
end;

procedure Merge(var a, tmp: ElementArray; from1, till2: Int32);
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
        If Less(tmp[from2], (tmp[from1])) then a[p] := tmp[inc1(from2)] else a[p] := tmp[inc1(from1)];
      end;
    end;
  end;
end;

procedure Sort(var a, tmp: ElementArray; from, till: Int32);
var
  middle: Int32;
begin
  middle := (from + till) div 2;
  If from < middle then Sort(a, tmp, from, middle);
  If middle+1 < till then Sort(a, tmp, middle+1, till);
  Merge(a, tmp, from, till);
end;

var
  i, j, n, m: Int32;
  a, b, tmp: ElementArray;
  ans: Int64;

begin
  ReadLn(n);
  For i := 1 to n do
  begin
    Read(a[i].number);
    ReadLn(a[i].money);
  end;
  ReadLn(m);
  For j := 1 to m do
  begin
    Read(b[j].number);
    ReadLn(b[j].money);
  end;

  Sort(a, tmp, 1, n);
  Sort(b, tmp, 1, m);

  ans := 0;
  i := 1;
  j := 1;
  While (i <= n) or (j <= m) do
  begin
    If i > n then
    begin
      inc(ans, b[j].money);
      inc(j);
      Continue;
    end;
    If j > m then
    begin
      inc(ans, a[i].money);
      inc(i);
      Continue;
    end;

    If (a[i].number = b[j].number) then
    begin
      inc(ans, max(a[i].money, b[j].money));
      inc(i);
      inc(j);
    end else
    begin
      If (a[i].number < b[j].number) then
      begin
        inc(ans, a[i].money);
        inc(i);
      end else
      begin
        If (b[j].number < a[i].number)  then
        begin
          inc(ans, b[j].money);
          inc(j);
        end;
      end;
    end;
  end;
  WriteLn(ans) ;
  readln;
end.