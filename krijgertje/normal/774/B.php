<?php
class Cup { public $val,$cost; };
class Big { public $hi,$lo; };
function bigcmp($p,$q) { if($p->hi!=$q->hi) return $p->hi-$q->hi; return $p->lo-$q->lo; }
$BASE = 1000000000;
function bigadd($p,$q) { global $BASE; $ret=new Big(); $ret->hi=$p->hi; $ret->lo=$p->lo+$q; while($ret->lo>=$BASE) { $ret->lo-=$BASE; $ret->hi++; } return $ret; }
function bigsub($p,$q) { global $BASE; $ret=new Big(); $ret->hi=$p->hi; $ret->lo=$p->lo-$q; while($ret->lo<0) { $ret->lo+=$BASE; $ret->hi--; } return $ret; }
function cupcmp($p,$q) { if($p->val!=$q->val) return $q->val-$p->val; return $p->cost-$q->cost; }

fscanf(STDIN,"%d%d%d",$na,$nb,$have);
$a=array_fill(0,$na,new Cup());
for($i=0;$i<$na;++$i) { $a[$i]=new Cup(); fscanf(STDIN,"%d%d",$a[$i]->val,$a[$i]->cost); }
$b=array_fill(0,$nb,new Cup());
for($i=0;$i<$nb;++$i) { $b[$i]=new Cup(); fscanf(STDIN,"%d%d",$b[$i]->val,$b[$i]->cost); }
usort($a,"cupcmp");
usort($b,"cupcmp");

//$na=$nb=100000; $have=1000000000;
//$a=array_fill(0,$na,new Cup()); for($i=0;$i<$na;++$i) { $a[$i]=new Cup(); $a[$i]->val=1000000000; $a[i]->cost=1; }
//$b=array_fill(0,$nb,new Cup()); for($i=0;$i<$nb;++$i) { $b[$i]=new Cup(); $b[$i]->val=1000000000; $b[i]->cost=1; }

//for($i=0;$i<$na;++$i) printf("%d %d\n",$a[$i]->val,$a[$i]->cost); printf("\n");
//for($i=0;$i<$nb;++$i) printf("%d %d\n",$b[$i]->val,$b[$i]->cost); printf("\n");

if($a[0]->cost+$b[0]->cost>$have) { printf("0\n"); return; }
$ai=0; $bi=0; $curcost=$a[0]->cost+$b[0]->cost; $curval=bigadd(bigadd(new Big(),$a[0]->val),$b[0]->val); $ret=$curval;
while(true) {
    while($curcost>$have&&$bi>0) { $curcost-=$b[$bi]->cost; $curval=bigsub($curval,$b[$bi]->val); --$bi; }
    //printf("a=[0..%d] b=[0..%d] -> %d %d\n",$ai,$bi,$curcost,$curval);
    if($curcost>$have) break;
    while($bi+1<$nb&&$curcost+$b[$bi+1]->cost<=$have) { ++$bi; $curcost+=$b[$bi]->cost; $curval=bigadd($curval,$b[$bi]->val); }
    //printf("a=[0..%d] b=[0..%d] -> %d %d\n",$ai,$bi,$curcost,$curval);
    if(bigcmp($curval,$ret)>0) $ret=$curval;
    ++$ai; if($ai>=$na) break; $curcost+=$a[$ai]->cost; $curval=bigadd($curval,$a[$ai]->val);
}
//print_r($ret);
if($ret->hi>0) {
    printf("%d%09d\n",$ret->hi,$ret->lo);
} else {
    printf("%d\n",$ret->lo);
}
//printf("%d\n",$ret);

?>